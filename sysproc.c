#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "syscall.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int isPrime(int n)
{
    if (n <= 1)  return 0;
    if (n <= 3)  return 1;
    if (n%2 == 0 || n%3 == 0) return 0;
   
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
          return 0;
   
    return 1;
}
int
sys_find_prime_number(void)
{
  int n;
  if(argint(0, &n) < 0)
    return -1;
  
  int prime = n; 
  int found = 0;
     
  while(!found)
  {
    prime++;
    if(isPrime(prime))
    {
        found = 1;
    }
  }
  return prime;
}

int
sys_get_call_count(void) {
  int syscall_number;
  if(argint(0, &syscall_number) < 0)
    return -1;
  
  return get_call_count(syscall_number);
}

int sys_wait_for_process(void) {
  int pid;
  if(argint(0, &pid) < 0)
    return -1;

  return wait_for_process(pid);
}