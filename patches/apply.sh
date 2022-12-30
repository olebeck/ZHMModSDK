cat imgui-dx12-mingw.patch | patch -d ../External/imgui/source -p1 -N -r /dev/null
cat directxtk12-ignore-shader-errors.patch | patch -d ../External/DirectXTK12 -p1 -N -r /dev/null --binary
cat directxtk12-wine.patch | patch -d ../External/DirectXTK12 -p1 -N -r /dev/null
cat vcpkg-patch-support-linux.patch | patch -d ../External/vcpkg -p1 -N -r /dev/null
