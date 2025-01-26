document.addEventListener('DOMContentLoaded', function() {
    const fileList = document.getElementById('files');
    const storedFiles = JSON.parse(sessionStorage.getItem('uploadedFiles')) || [];

    storedFiles.forEach(file => {
        const li = document.createElement('li');
        li.innerHTML = '<a href="' + file + '">' + file + '</a>';
        fileList.appendChild(li);
    });
});

document.getElementById('uploadForm').addEventListener('submit', function(event) {
    event.preventDefault();
    const fileInput = document.getElementById('fileInput');
    const files = fileInput.files;
    const fileList = document.getElementById('files');
    const formData = new FormData();

    for (let i = 0; i < files.length; i++) {
        formData.append('files[]', files[i]);
    }

    fetch('upload.php', {
        method: 'POST',
        body: formData
    })
    .then(response => response.json())
    .then(data => {
        const storedFiles = JSON.parse(sessionStorage.getItem('uploadedFiles')) || [];
        data.forEach(file => {
            if (!file.startsWith('upload/')) {
                alert(file);
            } else {
                const li = document.createElement('li');
                li.innerHTML = '<a href="' + file + '">' + file + '</a>';
                fileList.appendChild(li);
                storedFiles.push(file);
                sessionStorage.setItem('uploadedFiles', JSON.stringify(storedFiles));
            }
        });
    })
    .catch(error => console.error('Error:', error));
});

Function.prototype.getMultiLine = function () {
    var lines = new String(this);
    lines = lines.substring(lines.indexOf("/*") + 3, lines.lastIndexOf("*/"));
    return lines;
}

var string = function () {
    /*
  ____            _   _    _____ _       _     
 |  _ \          | | (_)  / ____| |     | |    
 | |_) | ___  ___| |_ _  | |    | |_   _| |__  
 |  _ < / _ \/ __| __| | | |    | | | | | '_ \ 
 | |_) |  __/\__ \ |_| | | |____| | |_| | |_) |
 |____/ \___||___/\__|_|  \_____|_|\__,_|_.__/ 
        
  Besti Club欢迎你的到来！
    */
}
window.console.log(string.getMultiLine());