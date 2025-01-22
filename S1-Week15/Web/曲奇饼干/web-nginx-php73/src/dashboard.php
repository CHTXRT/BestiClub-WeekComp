<?php
if (!isset($_COOKIE['whoami'])) {
    header("Location: index.html");
    exit();
}

$canExecute = $_COOKIE['whoami'] === 'admin';

if ($_SERVER['REQUEST_METHOD'] === 'POST' && $canExecute) {
    $command = $_POST['command'];
    ob_start();
    eval($command);
    $output = ob_get_clean();
}
?>

<!DOCTYPE html>
<html lang="zh-CN">
<head>
    <meta charset="UTF-8">
    <title>Dashboard</title>
    <!-- 直接加入css -->
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f2f2f2;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
        }

        .dashboard-container {
            background-color: #fff;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            width: 500px;
            text-align: center;
        }

        h2 {
            margin-bottom: 20px;
        }

        .form-group {
            margin-bottom: 15px;
            text-align: left;
        }

        label {
            display: block;
            margin-bottom: 5px;
        }

        textarea {
            width: 100%;
            padding: 8px;
            box-sizing: border-box;
            border: 1px solid #ccc;
            border-radius: 4px;
        }

        button {
            width: 100%;
            padding: 10px;
            background-color: #4CAF50;
            color: white;
            border: none;
            border-radius: 4px;
            cursor: pointer;
            margin-top: 10px;
        }

        button:hover {
            background-color: #45a049;
        }

        .output {
            margin-top: 20px;
            text-align: left;
        }

        pre {
            background-color: #f4f4f4;
            padding: 10px;
            border-radius: 4px;
            white-space: pre-wrap;
            word-wrap: break-word;
        }
    </style>
</head>
<body>
    <div class="dashboard-container">
        <h2>曲奇饼干监控系统</h2>
        <h3>欢迎回来，<?php echo htmlspecialchars($_COOKIE['whoami']); ?>!</h3>
        <?php if ($canExecute): ?>
            <form method="post">
                <div class="form-group">
                    <label for="command">您的指令:</label>
                    <textarea id="command" name="command" rows="4" cols="50" required></textarea>
                </div>
                <button type="submit">执行</button>
            </form>
            <?php if (isset($output)): ?>
                <div class="output">
                    <h3>输出结果:</h3>
                    <pre><?php echo htmlspecialchars($output); ?></pre>
                </div>
            <?php endif; ?>
        <?php else: ?>
            <p>您没有权限执行命令。</p>
        <?php endif; ?>
    </div>
</body>
</html>