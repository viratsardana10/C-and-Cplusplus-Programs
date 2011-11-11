        #include <iostream>
        #include <string>
        using namespace std;
         
        void permute( string prefix, string s )
        {
             int length=s.size();
  
          if ( s.size() <= 1  )
                cout <<prefix <<s <<"\n";
  
          else
  
           //  for ( char *p = s.begin(); p <s.end(); p++ )
           char* p=s.begin();
              for(int i=0;i<length;i++)
              {
                 
                  char c = s[i];
                    s.erase( c );
  
                permute( prefix + c, s );
                    s.insert( p, c );
                }
        }
         
  
    int  main()
  
      {
  
          permute( "", "12345" );
  
          return 0;
  
      }

