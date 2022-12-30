conf=$1
dxc_folder=_build/x64-${conf}-Mingw/vcpkg_installed/x64-linux/tools/directx-dxc
chmod +x ${dxc_folder}/dxc.exe
cp ${dxc_folder}/dxc.exe ${dxc_folder}/DXC.EXE

cmake --preset x64-${conf}-Mingw .
cmake --build _build/x64-${conf}-Mingw 
