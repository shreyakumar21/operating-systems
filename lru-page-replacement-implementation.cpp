
#include<bits/stdc++.h>
using namespace std;
  

int pageFaults(int pages[], int n, int capacity)
{
    
    unordered_set&lt;int&gt; s;
  
   
    unordered_map&lt;int, int&gt; indexes;
  
    int page_faults = 0;
    for (int i=0; i&lt;n; i++)
    {
       
        if (s.size() &lt; capacity)
        {
           
            if (s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);
  
      
                page_faults++;
            }
  
    
            indexes[pages[i]] = i;
        }

        else
        {

            if (s.find(pages[i]) == s.end())
            {

                int lru = INT_MAX, val;
                for (auto it=s.begin(); it!=s.end(); it++)
                {

                    if (indexes[*it] &lt; lru)
                    {
                        lru = indexes[*it];
                        val = *it;
                    }
                }
  
               
                s.erase(val);
  
        
                s.insert(pages[i]);
  
           
                page_faults++;
            }
  
       
            indexes[pages[i]] = i;
        }
    }
  
    return page_faults;
}
  
// Driver code
int main()

{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 4;
    cout &lt;&lt; pageFaults(pages, n, capacity);
    return 0;
}