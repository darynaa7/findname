cd \AppLib\findfile\Lib
call runlib.bat

cd \AppLib\findfile\App
rmdir /s /q build_app
mkdir build_app
cd  build_app
cmake ..
cmake --build .
start bin\Debug\app.exe



