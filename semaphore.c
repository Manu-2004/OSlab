 #include<stdio.h>
 #include<pthread.h>
 #include<semaphore.h>

#define NUM_THREADS 2
 intcounter = 0;
 sem_t semaphore;

 void* increment_counter (void*arg)
{
 for(int i=0; i<5; i++)
 {
  sem_wait(&semaphore); // Wait on the semaphore to acquire the lock
  counter++;           // Increment the shared counter variable
  printf("Counter value: %d\n",counter); // Print the current value of counter
  sem_post(&semaphore); // Release the semaphore to release the lock
 }
  
 pthread_exit(NULL);  // Exit the thread
 }

 void main()
{
  pthread_t threads[NUM_THREADS]; // Array to hold thread IDs
   sem_init(&semaphore,0,1);  // Initialize semaphore with initial value 1
  
   for(int i=0;i < NUM_THREADS; i++) 
  {
    pthread_create(&threads[i],NULL, increment_counter,NULL);  // Create a thread and pass increment_counter as the thread function
 }
  // Join all threads to wait for them to finish
   for(inti = 0;i < NUM_THREADS; i++)
   {
   pthread_join(threads[i],NULL); // Wait for thread i to finish
   }
  
 sem_destroy(&semaphore); // Destroy the semaphore
 }
