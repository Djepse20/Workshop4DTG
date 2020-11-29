#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Denne funktion skal returnere 1 hvis x er et primtal og 0 ellers */
int isPrime(int x){
  int i;
  for(i= 1;i<x-1;i++)
    if(!(x%i))
      return 0;

  return 1;
}

/* Denne funktion skal returnere 1 hvis gcd(x,2)=1 og 0 ellers */
int isGcd1(int x){
return ((x%2)==1);
}

/* Denne funktion skal returnere 1 hvis 9^x-2 mod 5 = 2 og 0 ellers */ 
/* tror han mener 9^x og så trækker man 2 fra og siger modulo 5 da at ellers får man aldrig 2 :)*/
/* har tjekket med lommeregner at metoden herunder giver det ønskede resultat bare rolig :D*/
int is2mod5(int x){
   unsigned int ans = (9%5)-2;
    unsigned int mul = ans; 
  
    // now multiply ans by b-1 times and take 
    // mod with m 
    for (unsigned int i=1; i<x; i++) 
        ans = ((ans*mul)-2)%5; 
    

    return (ans == 2); 
}


int main(void){
  int x;
  int p, q= 0, r;

  printf("Hvilket heltal vil du tjekke?\n");
  scanf("%d",&x); 

  p = isPrime(x);
  q = isGcd1(x);
  r = is2mod5(x);
  
  printf("%d,%d,%d",p,q,r);
  


  if ((p && !r) || !(p || !q || r) || (!p && !q && r)){
    printf("Du fandt et x\n");
    printf("p er %d, q er %d, and r er %d\n", p,q,r);
  } else {
    printf("Proev igen\n");
  }

  return EXIT_SUCCESS;
}