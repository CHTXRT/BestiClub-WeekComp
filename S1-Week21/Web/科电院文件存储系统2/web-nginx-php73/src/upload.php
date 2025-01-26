<?php
$uploadDir = 'upload/';
$response = [];
$allowedTypes = ['image/jpeg', 'image/png', 'image/gif', 'application/pdf']; // 允许的Content-Type类型


if (!file_exists($uploadDir)) {
    mkdir($uploadDir, 0777, true);
}

foreach ($_FILES['files']['name'] as $key => $name) {
    $tmpName = $_FILES['files']['tmp_name'][$key];
    $filePath = $uploadDir . basename($name);
    $fileType = $_FILES['files']['type'][$key];

    if (in_array($fileType, $allowedTypes)) {
        if (move_uploaded_file($tmpName, $filePath)) {
            $response[] = $filePath;
        } else {
            $response[] = "Failed to upload $name";
        }
    } else {
        $response[] = "File type not allowed: $name";
    }
}

header('Content-Type: application/json');
echo json_encode($response);
?>