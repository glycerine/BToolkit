MACHINE         std_logic_PK

CONSTANTS
   
    std_logic,

/*" \{ {\em 0\/} , {\em 1\/} \} also recognized as {\em std\_logic} "*/

    vand, vor, vxor, vnot

PROPERTIES 

    std_logic = {0,1}   &

    vand : std_logic*std_logic --> std_logic &
    vor  : std_logic*std_logic --> std_logic &
    vxor : std_logic*std_logic --> std_logic &
    vnot : std_logic     --> std_logic & 

    vand(1,1) = 1 &  
    vand(0,1) = 0 &
    vand(1,0) = 0 &
    vand(0,0) = 0 &

    vor(1,1) = 1 &
    vor(0,1) = 1 &
    vor(1,0) = 1 &
    vor(0,0) = 0 &

    vxor(1,1) = 0 & 
    vxor(0,1) = 1 &
    vxor(1,0) = 1 &
    vxor(0,0) = 0 &
   

    vnot(0) = 1 &
    vnot(1) = 0


END
