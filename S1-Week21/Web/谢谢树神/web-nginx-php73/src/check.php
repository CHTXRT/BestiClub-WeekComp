<?php
session_start();

if (!isset($_SESSION['nums'])) {
    $_SESSION['nums'] = 0;
    echo "index.html";
}
elseif ($_SESSION['nums'] >= 1000) {
    echo "Tree_1s_my_sun.php";
}
else {
    $_SESSION['nums']++;
    echo "index.html";
}
?>