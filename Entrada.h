#TOTAL EXITOSAS = 13


#----------------------------MKDISK Y RMDISK (6 Ejecutadas)(4 exitosas)---------------------------------------------------------------------|

#Contenido de calificacion.sh
#Crea tres discos de 30 Mb
mkdisk -Size::30 +uniT::M \
-path::"/home/carlos/discos_cache/semestre/" -name::"Disco1.dsk"

#Elimina Disco1.dsk
rmDisk -path::/home/carlos/discos_cache/semestre/Disco1.dsk

mkdisk -Size::40 +unit::M -path::"/home/carlos/discos_cache/semestre/" -name::"Disco2.dsk"

#falla xq le faltan parametros
mkdisk -Size::50 +unIt::M -patH::"/home/carlos/discos_cache/semestre/"

#Crea un disco de 3000 Kb en la carpeta home
Mkdisk -Size::40000 +unit::K -path::"/home/carlos/discos_cache/semestre/" \
-name::"Disco4.dsk"

#no exitoso pues faltan parametros
mkDisk -size::30 -patH::"/home/Disco4.dsk"

#-----------------------------FDISK (9 ejecutadas)(9 exitosas)--------------------------------------------------------------------------------|

#Crea una partición primaria llamada Particion1 de 300 kb
#con el peor ajuste en el disco Disco1.dsk
fdisk -Size::3000 -path::/home/carlos/discos_cache/semestre/Disco2.dsk -name::"Particion1"
fdisk -Size::3000 -path::/home/carlos/discos_cache/semestre/Disco2.dsk -name::"Particion2"
fdisk -Size::3000 -path::/home/carlos/discos_cache/semestre/Disco2.dsk -name::"Particion3"

#Crea una partición primaria llamada Particion1 de 300 kb
#con el peor ajuste en el disco Disco4.dsk
fdisk -Size::5000 -path::/home/carlos/discos_cache/semestre/Disco4.dsk -name::"Particion11"
fdisk -Size::3000 -path::/home/carlos/discos_cache/semestre/Disco4.dsk -name::"Particion12"
fdisk -Size::3000 -path::/home/carlos/discos_cache/semestre/Disco4.dsk -name::"Particion13"

#Error exede el numero de primarias +2errores crear particion
fdisk -Size::300 -path::/home/carlos/discos_cache/semestre/Disco2.dsk -name::"Particion4"
fdisk -Size::300 -path::/home/carlos/discos_cache/semestre/Disco2.dsk -name::"Particion5"

#Crea una partición extendida dentro de Disco2 de 300 kb
#Tiene el peor ajuste
fdisk +type::E -path::"/home/carlos/discos_cache/semestre/Disco2.dsk" +Unit::K \
-name::"ParticionE" -size::4000

#Crea una partición lógica con el mejor ajuste, llamada Particion3,
#de 1 Mb en el Disco3
fdisk -size::1 +type::L +unit::M +fit::BF \
-path::"/home/carlos/discos_cache/semestre/Disco2.dsk" -name::"ParticionL1"

#Elimina de forma rápida una partición llamada Particion2
#fdisk +delete::fast -name::"Particion2.1" \
#-path::"/home/carlos/discos_cache/semestre/Disco2.dsk"

#Elimina de forma completa una partición llamada Particion1
#fdisk -name::"Particion1" +delete::full \
#-path::"/home/carlos/discos_cache/semestre/Disco2.dsk"

#Crea una partición lógica con el mejor ajuste, llamada Particion3,
#de 1 Mb en el Disco3
fdisk -size::1 +type::L +unit::M +fit::BF \
-path::"/home/carlos/discos_cache/semestre/Disco2.dsk" -name::"ParticionL2"

#Crea una partición lógica con el mejor ajuste, llamada Particion3,
#de 1 Mb en el Disco3
fdisk -size::1 +type::L +unit::M +fit::BF \
-path::"/home/carlos/discos_cache/semestre/Disco2.dsk" -name::"ParticionL3"

#DEtalles de un Disco
lspart -path::"/home/carlos/discos_cache/semestre/Disco2.dsk"

#Montar Particion2.1
mount -path::"/home/carlos/discos_cache/semestre/Disco2.dsk" -name::"Particion1" 

#Montar Particion1
mount -path::"/home/carlos/discos_cache/semestre/Disco2.dsk" -name::"Particion2" 

#Montar Particion1.1
mount -path::"/home/carlos/discos_cache/semestre/Disco4.dsk" -name::"Particion11" 

#Montar Particion1.2
mount -path::"/home/carlos/discos_cache/semestre/Disco4.dsk" -name::"Particion12" 


#mostrar Lista de Montadas
mount

#Reporte De MBR 
rep -id::vda1 -path::"/home/carlos/discos_cache/semestre/reporteMBR.pdf" -name::mbr
rep -id::vdb1 -path::"/home/carlos/discos_cache/semestre/reporteMBR2.pdf" -name::mbr
rep -id::vda1 -path::"/home/carlos/discos_cache/semestre/reporteDisk1.pdf" -name::disk
rep -id::vdb1 -path::"/home/carlos/discos_cache/semestre/reporteDisk2.pdf" -name::disk


#------------------COMANDOS ADD
#fdisk +add::1 +unit::M -path::"/home/carlos/discos_cache/semestre/Disco4.dsk" -name::"Particion12"
#fdisk -add::1 +unit::M -path::"/home/carlos/discos_cache/semestre/Disco4.dsk" -name::"Particion11"
#rep -id::vdb1 -path::"/home/carlos/discos_cache/semestre/reporteDisk2.pdf" -name::disk







