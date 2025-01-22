<?php
if (isset($_COOKIE['whoami'])) {
    header("Location: dashboard.php");
    die();
}
?>

<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="UTF-8">
    <title>曲奇饼干监控系统</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class="login-container">
        <h2>登录</h2>
        <form action="login.php" method="post">
            <div class="form-group">
                <label for="username">用户名:</label>
                <input type="text" id="username" name="username" required>
            </div>
            <div class="form-group">
                <label for="password">密码:</label>
                <input type="password" id="password" name="password" required>
            </div>
            <button type="submit">登录</button>
        </form>
        <form action="guest_login.php" method="post">
            <button type="submit" class="guest-login">游客登录</button>
        </form>
    </div>
    <script src="script.js"></script>
</body>
</html>