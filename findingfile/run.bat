cd \AppLib\findfile\findfile
call runlib.bat

cd \AppLib\findfile\findingfile
rmdir /s /q build_app
mkdir build_app
cd  build_app
cmake ..
cmake --build .
start bin\Debug\app.exe



