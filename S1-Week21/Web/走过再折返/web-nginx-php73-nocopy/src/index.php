<?php
highlight_file(__FILE__);

if(isset($_POST['a']) and isset($_POST['b'])){
    $a = $_POST['a'];
    $b = $_POST['b'];
    if(strcmp('', $b) != 0 and md5($a.$b) == md5($a)){
        if(isset($_POST['cmd'])){
            eval($_POST['cmd']);
        }
    }
}

?>