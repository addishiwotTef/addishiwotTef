    #include <iostream>
    using namespace std;

    int mid, last, first, x, col=6, row=7;
    bool found=0;
    int marx[][6] = {{1, 33,55,78,100,131},{10,36,57,80,106,136},{17,39,61,83,107,149},
                {23,45,67,84,110,153}, {27,49,70,87,115,158},
                {30,51,74,93,121,162},{32,53,76,97,127,167}};
    int dtb[6];     //= {0,3,4,5,6,22};
    bool binry_search(int db[], int size, int key)        // Binary search
                  {
                      last = size-1;
                      first = 0;
                      while(last>=first && !found)
                      {
                      mid = (last + first)/2;
                      if(db[mid]==key)
                        found=1;
                      else if(key>db[mid])
                      {
                            first = mid+1;
                      }
                          else
                          {
                            last = mid-1;
                          }

                      }
                    return found;
                  }
     int main()
     {
         cout<<"Enter the number you need to search."<<endl;
         cin>>x;
         if(x<marx[0][0] || x>marx[row-1][col-1])       // considering that our matrix is sorted, no need to call the
                 found =0;                              // binary search if this conditions are fulfilled

         else
             for(int j=0; j<row&&!found; j++)           // j counts the rows
             {
                if(x==marx[j][0])                       // if the number is fortunately found at the first element of the
                    found=1;                            // row, no need to apply a binary search

                else if(x>marx[j][0])
                    if(x==marx[j][col-1])               // if the number is fortunately found at the last element of the
                       found=1;                         // row, no need to apply a binary search

                    else if(x<marx[j][col-1])           // checking if the number is less than the last element of the row
                        {
                           for(int i=0; i<col; i++)     // i counts the columns
                           {
                               dtb[i]= marx[j][i];      // to pass a specific row out of the matrix to the
                                                        // binary search function
                           }
                           binry_search(dtb, col, x);
                        }
             }

        cout <<"found = "<<found <<endl;
        return 0;
     }




