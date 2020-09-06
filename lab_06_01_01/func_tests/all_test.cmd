@ECHO OFF
FOR /L %%B IN (1,1,6) DO (call pos_test.cmd 0%%B)
FOR /L %%B IN (1,1,10) DO (call neg_test.cmd 00%%B)
DEL out.txt