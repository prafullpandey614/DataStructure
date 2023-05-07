string s1;
        string s2;
        int l=str.size();
        int i=0;
        for( i=0;i<l-1;i++)
        {
            if(i==0)
            {
            if(str[i]<=str[i+1])
            {
                break;
            }
            else
            {
            s1.push_back(str[i]);
            s2.push_back(str[i]);
            }
            }
            else
            {
               if(str[i]<str[i+1])
            {
                break;
            }
            else
            {
            s1.push_back(str[i]);
            s2.push_back(str[i]);
            } 
            }
        }
        s1.push_back(str[i]);
        s2.push_back(str[i]);
        reverse(s2.begin(),s2.end());
        
        s1.append(s2);
        return s1;
