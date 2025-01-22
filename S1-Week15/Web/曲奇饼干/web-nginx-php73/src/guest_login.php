<?php
// 设置游客登录的cookie
setcookie('whoami', 'guest', time() + 3600, "/"); // Cookie 有效期为1小时
header('Location: dashboard.php');
exit();
?>