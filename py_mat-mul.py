#!/usr/bin/env python
# coding: utf-8

# In[88]:


import numpy as np
import time


# In[89]:


n = 300;C_ = 0;


# In[90]:


A = np.random.randint(100,size = (n,n));
B = np.random.randint(100,size = (n,n));
C = np.zeros((n,n));


# In[91]:


start = time.time();
for i in range(n):
    for j in range(n):
        for k in range(n):
            C[i][j] = C_ + A[j][k] * B[k][j] ; 
        
    C_ = 0;
end = time.time();


# In[92]:


print("Time  = ", end-start);


# In[ ]:




