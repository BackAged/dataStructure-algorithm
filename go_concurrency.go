package main

import (
	"fmt"
	"strconv"
	"time"
)

// Payload pay
type Payload struct {
	id string
}

// UploadToS3 uploads
func (p *Payload) doWorkWithIt() error {
	fmt.Print("processing the payload")
	time.Sleep(2 * time.Millisecond)
	return nil
}

// Job represents the job to be run
type Job struct {
	Payload Payload
}

// JobQueue A buffered channel that we can send work requests on.
var JobQueue = make(chan Job, 2500)

// Worker represents the worker that executes the job
type Worker struct {
	WorkerPool chan chan Job
	JobChannel chan Job
	quit       chan bool
	id         string
}

// NewWorker ne
func NewWorker(workerPool chan chan Job, id string) Worker {
	return Worker{
		WorkerPool: workerPool,
		JobChannel: make(chan Job),
		quit:       make(chan bool),
		id:         id,
	}
}

// Start method starts the run loop for the worker, listening for a quit channel in
// case we need to stop it
func (w Worker) Start() {
	go func() {
		for {
			// register the current worker into the worker queue.
			w.WorkerPool <- w.JobChannel
			fmt.Println("worker " + w.id + " says my ass is free here, give me some more!!")

			select {
			case job := <-w.JobChannel:
				fmt.Println("worker " + w.id + "says, ya, deeper!! => " + job.Payload.id)
				if err := job.Payload.doWorkWithIt(); err != nil {
					fmt.Print(err.Error())
				}
				fmt.Println("worker " + w.id + " says, hell no, it's bent again!! => " + job.Payload.id)

			case <-w.quit:
				return
			}
		}
	}()
}

// Stop signals the worker to stop listening for work requests.
func (w Worker) Stop() {
	go func() {
		w.quit <- true
	}()
}

// Dispatcher des
type Dispatcher struct {
	WorkerPool chan chan Job
	maxWorkers int
}

// NewDispatcher does
func NewDispatcher(maxWorkers int) *Dispatcher {
	pool := make(chan chan Job, maxWorkers)
	return &Dispatcher{WorkerPool: pool, maxWorkers: maxWorkers}
}

// Run run
func (d *Dispatcher) Run() {
	fmt.Println("spawning worker")
	for i := 0; i < d.maxWorkers; i++ {
		worker := NewWorker(d.WorkerPool, strconv.Itoa(i+1))
		worker.Start()
		fmt.Println("worker " + strconv.Itoa(i+1) + " started working")
	}
	go d.dispatch()
}

func (d *Dispatcher) dispatch() {
	for {
		select {
		case job := <-JobQueue:
			fmt.Println("dispatcher found job => " + job.Payload.id)
			go func(job Job) {
				jobChannel := <-d.WorkerPool
				jobChannel <- job
				fmt.Println("found a worker => " + job.Payload.id)
				fmt.Println("delivered job to worker => " + job.Payload.id)
			}(job)
		}
	}
}

func produceJobs() {
	fmt.Println("producing jobs")
	for i := 1; i < 6; i++ {
		JobQueue <- Job{Payload{id: "something" + strconv.Itoa(i)}}
		fmt.Println("produced jobs => " + strconv.Itoa(i))
	}
}

func main() {
	fmt.Println("started my server")

	d := NewDispatcher(2500)
	d.Run()

	for {
		go produceJobs()
	}
}
