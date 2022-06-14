#include<iostream>
#include<chrono> // time

#define region 7  //constant value
using namespace std;

//adjacency matrix for the given graph
int adjMatrix[region][region] = 
{
   {0, 1, 0, 1, 1, 0, 0},
   {1, 0, 1, 1, 0, 0, 0},
   {0, 1, 0, 1, 0, 1, 1},
   {1, 1, 1, 0, 1, 1, 0},
   {1, 0, 0, 1, 0, 1, 0},
   {0, 0, 1, 1, 1, 0, 1},
   {0, 0, 1, 0, 0, 1, 0}
};

void greedyAlgorithm() 
{
  
   int color[region];   //holds the colors
   color[0] = 1;        //first color is assigned to one
   
   int i = 1;
   while(i != region)
   {
      color[i] = 0;     //all other colors unassigned at first
      i++;
   }

   bool colorExist[region];
   for(int tempEx = 0; tempEx<region; tempEx++)
   {
      colorExist[tempEx] = false;    //any colors are not chosen at first
   }      
   
   for(int j = 1; j<region; j++) 
   {    
      for(int k = 0; k<region; k++) 
      {
         if(adjMatrix[j][k] && color[k] != -1)
         {
            //if color is assigned, mark it as selected
            colorExist[color[k]] = true;   
         }
     }

      int tempColor = 0;
      while(tempColor < region)
      {
         if(!colorExist[tempColor]) //color that is not assigned
         {
            break;
         }
         tempColor++;
      }
            
      color[j] = tempColor;    //found color assigned
            
      for(int k = 0; k<region; k++) 
      {    //to make next phase, color exist assigned false
         if(adjMatrix[j][k] && color[k] != 0) 
         {
                  colorExist[color[k]] = false;
         }
      }  
   }
   int max = 0;      //check the max number of colors used
   int temp = 0;     //temp is the element of the matrix

   while(temp<region)
   {
      cout <<"Vertex " << temp + 1 << " ---> " << "Color " << color[temp] <<endl;
      if(color[temp] > max)
      {
         max = color[temp];
      }
      temp++;
   }
   cout << "Number of different colors: " << max << endl;
   
}

int main() 
{
   chrono::steady_clock::time_point _start(std::chrono::steady_clock::now());//clock starts
   greedyAlgorithm();
   chrono::steady_clock::time_point _end(std::chrono::steady_clock::now());//clock ends
   cout << "Time in " << std::chrono::duration_cast<std::chrono::duration<double> >(_end - _start).count() * 1000 << " ms"<<endl;
}