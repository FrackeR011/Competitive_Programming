/*
 This program finds the samllest palindormes larger than entered numbers.
 The numbers will be stored in que of characters becease -
 Numbers can be very large so no data type can handle them.
 Insertion and deletion at ends will take place for which deque is  suitable.

*/

#include <iostream>
#include <deque>

std::deque <char> next_palindorme( std::deque <char> &vect ) 
{
   // This function takes a deque as an arguement and returns the smallest palindrome larger than that number  
    int len = vect.size();
    int mid;
    std::deque <char> result;
   //  Procedure to find the number depends upon whether the number has even number of digits or not

    if((len%2)==0)    // For even number of digits
    {
        mid=(len/2)-1;
        int counter = 0;

        for(int i = 0 ; i<=mid ; i++)
            if(vect[mid-i]>vect[mid+i+1])   // Checking whether first half of string is larger than second half
            {    
                counter = 1;                 
                break;
            }    
            else if(vect[mid-i]<vect[mid+1+i])
            {
                break;
            }
            
            
        if(counter==1)
        {
            
            for(int g=0;g<(vect.size())/2;g++)
                result.push_back(vect[g]);            
            /*std::copy(vect.begin(),vect.begin()+mid,back_inserter(result));*/
            for(int i=0; i<=mid ; i++)
                result.push_back(vect[mid-i]);
            
            return result;

        }    
        else 
        {    
            
            for(int g=0;g<(vect.size())/2;g++)
                result.push_back(vect[g]);
            /*std::copy(vect.begin(),vect.begin()+mid-1,back_inserter(result)); */
            if(result[mid]!='9')
                result[mid]++;
            else
            {
                int k=0;
                while(((mid-k)>=0)&&result[mid-k]=='9')
                {
                    result[mid-k]='0';
                    k++;
                }

                if((mid-k)>=0)
                    result[mid-k]++;
                else
                    result.insert(result.begin(),'1');
                
            }

            for(int i=0; i<=mid ; i++)
                result.push_back(result[mid-i]);
            
            return result;              
        } 
    }    
    else if(len==1&&vect[0]=='9')
    {
        
        result.push_back('1');
        result.push_back('1');
        return result;
        
    }
    else
    {   
        
        mid=len/2;
        int counter = 0;
        
        for(int i = 0 ; i<mid ; i++)
            if(vect[mid-i-1]>vect[mid+i+1])
            {   
                counter = 1;
                break;
            }    
            else if(vect[mid-i]<vect[mid+1+i])
            {
                 break;
            }

        if(counter==1)
        {
            
            for(int g=0;g<(vect.size())/2+1;g++)
            result.push_back(vect[g]);            
            /*std::copy(vect.begin(),vect.begin()+mid,back_inserter(result));*/
            for(int i=0; i<mid ; i++)
                result.push_back(vect[mid-i-1]);     
            return result;      
        }
        else
        {
            
            for(int g=0;g<(vect.size())/2+1;g++)
            result.push_back(vect[g]);
            //std::copy(vect.begin(),vect.begin()+mid-1,back_inserter(result));
            if(result[mid]!='9')  
            {
                result[mid]++;              
            }
            else
            {
                int k = 0;
                while(((mid-k)>=0)&&result[mid-k]=='9')
                {
                    result[mid-k]='0';
                    k++;
                }

                if(mid-k>=0)
                    result[mid-k]++;
                else
                    result.insert(result.begin(),'1');

            }  
            
            for(int i=0; i<mid ; i++)
                result.push_back(result[mid-i-1]);
            return result;          

        }


    }    

}


int main( void )
{
    
    int o;  
    int count=0;
    int t;
    std::cin>>t;
    
    std::deque <std::deque <char>> numbers;
    std::deque <std::deque <char>> results;
    std::deque <char> testcase;
    std::cin>>std::noskipws;
    
    char c;
    std::cin.ignore();
    for(int i=0;i<t;i++)
    {
        o=1; 
        while(std::cin>>c&&c!='\n')
        { 
        
            if(o==1)
            {
                testcase.push_back(c);     // To always take first number be it 0 or not for corner case
                if(c!='0')
                count=1;
                  
            }
            else
            {
                if(c!='0')         //To remove leading zeros 
                count=1;
                
                if(count==1)
                testcase.push_back(c);
                
            }
        
        o++; 
        }   
      
        if(testcase.size()>1&&testcase[0]=='0')   // To handle corner case of only 1 leading zero
        {
           
            testcase.erase(testcase.begin());
        
        }
    
        numbers.push_back(testcase);
        testcase.clear();

    }   

    
    for(int j=0;j<t;j++)
    {
        results.push_back(next_palindorme(numbers[j]));
    
        for(int i = 0;i<results[j].size();i++)
        std::cout<<results[j][i];
        std::cout<<"\n";

    }
    
    return 0;

}







