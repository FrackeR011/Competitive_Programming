/*This program prints prime numbers between and including two numbers for t test cases. Segmented Sieve is used to mark nn prime numbers 
to increase efficiency compared to simple sieve*/


#include <vector>
#include <iostream>
#include <cmath>

void Segmented_Sieve( int a , int b )
{
	
	std::vector <int> primelist;   // Vector to store list of prime numbers less than sqrt(b)
	
    // Calculating primes less than b using Simple Sieve

    std::vector <bool> prime1;     // Vector to store condition corresponding to all numbers less than sqrt(b)
    prime1.assign( std::sqrt(b) , true );

    
    for(int i=2 ; i*i <= b ; i++ )
    {
    	if(prime1[i])
    		for( int j= 2*i ; j<= std::sqrt(b) ; j+=i )
    			prime1[j]= false;
    }
    
    
    for( int i=2 ; i*i <= b ; i++ )
    	if(prime1[i])
    	primelist.push_back(i);
    	
    //Normal Sieve ends here
    
    std::vector <bool> prime2;  // Vector to store condition for all numbers from a to b
  
    for(int q=0;q<b-a-1 ; q++)
    prime2.push_back(true);
   
    for( int i=0; i<primelist.size() ; i++ )
    {
    	int r=(a/primelist[i])*primelist[i];
       
    	for( int j=r+primelist[i]-a-1 ; j< b-a ; j+=primelist[i] )
    		 prime2[j]=false;
    		
    }
    
    for(int i=0;i<primelist.size() ; i++ )   // This loop is used to print all primenumbers lying between a and b which are less than sqrt(b)
    if(primelist[i]>a)
    std::cout<<primelist[i]<<"\n";
    
    for(int i=0; i<prime2.size() ; i++ )     
	if(prime2[i])
	std::cout<<a+i+1<<"\n";
    
}

int main(void)
{
	int t,i;
	std::cin>>t;
	
	int x,z;
	std::vector <int> l;     // vector to store lower and upper bounds
	std::vector <int> u;
	
	for(i=0 ; i<t ; i++ )
	{
	    std::cin>>x;
	    std::cin>>z;
	    l.push_back(x);     // push_back is used rather than cin 
	    u.push_back(z);
	    
	
/*	std::cin>>l[i]>>u[i]; do not use this method it gives error as elements of vector cannot be accesed without creating them*/
	}
	
	
	int counter1,counter2;     
	for(i=0 ; i<t ; i++)      // this loop is used for corner cases of lower and upper bounds being prime
	{
	counter1=0;
	counter2=0;
	for(int y=2;y<=std::sqrt( l[i] );y++)
	{
	if(!(l[i]%y))
	counter1=1;
	}
	for(int y=2;y<=sqrt( u[i]);y++)
	{
	if(!(u[i]%y))
	counter2=1;
	}
	if(!(counter1)&&(l[i]!=1))
	std::cout<<l[i]<<"\n";
	
	Segmented_Sieve( l[i] , u[i] );
	if(!counter2&&(u[i]!=1)&&(u[i]!=l[i]))   //Checking whether both bounds are equal
	std::cout<<u[i]<<"\n";                    // So not to print them twice
	std::cout<<"\n";
	}
	
	return 0;
}

