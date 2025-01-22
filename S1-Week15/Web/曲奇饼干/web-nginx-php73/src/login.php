<?php
if(isset($_POST['username']) && isset($_POST['password'])){
    $username = $_POST['username'];
    $password = $_POST['password'];
    if($username == 'admin' && $password == 'whjhjhsjha863ghg2y3t23bh1g3h2g1h3j12jjs'){
        //设置$_COOKIE['whoami'] = 'admin'
        setcookie('whoami', 'admin', time() + 3600, "/");
        header('Location: dashboard.php');
    }else{
        echo '用户名或密码错误';
        echo '<script>
                setTimeout(function() {
                    history.back();
                }, 1000);
              </script>';
    }
}