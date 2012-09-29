set gcjdir="C:\Documents and Settings\nnizhawa\My Documents\java\gcj\"
mkdir %1
copy "..\codegen\BaseSolution.java" %1
copy "..\codegen\README.txt" %1
cd %1
@echo off
"..\..\codegen\genclass.bat" %1 > %1.java


