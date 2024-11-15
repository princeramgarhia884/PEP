const path = require("path");
const fs = require("fs");
// let types = {
//     media: ["mp4", "mkv", "mp3", "mov"],
//     archives: ['zip', '7z', 'rar', 'tar', 'gz', 'ar', 'iso', "xz"],
//     documents: ['docx', 'doc', 'pdf', 'xlsx', 'xls', 'odt', 'ods', 'odp', 'odg', 'odf', '.txt', 'ps', 'tex', "csv", 'json'],
//     app: ['exe', 'dmg', 'pkg', "deb", "apk"],
//     images: ['png', 'jpg', 'jpeg']
// }
let types = {
    media: [".mp4", ".mkv", ".mp3", ".mov"],
    archives: ['.zip', '.7z', '.rar', '.tar', '.gz', '.ar', '.iso', ".xz"],
    documents: ['.docx', '.doc', '.pdf', '.xlsx', '.xls', '.odt', '.ods', '.odp', '.odg', '.odf', '.txt', '.ps', '.tex', ".csv", '.json'],
    app: ['.exe', '.dmg', '.pkg', ".deb", ".apk"],
    images: ['.png', '.jpg', '.jpeg']
}
// let filePath=path.join(__dirname,"../../wcat");
// fs.readdir(filePath, (err, files) => {
//     files.forEach(file => {
//     //   console.log(file);
//     });
//   });
//   console.log(process.cwd());
let currpath = undefined;
organising(currpath);
function organising(currpath) {
    if (currpath == undefined) {
        currpath = process.cwd();
        console.log(currpath);
    }
    let FilesArr = fs.readdirSync(currpath);
    console.log(FilesArr);
    for (let i = 0; i < FilesArr.length; i++) {
        // console.log(arr[i]);
        let fullPath = path.join(currpath, FilesArr[i]);
        // console.log(fullPath);
        let isFile = fs.lstatSync(fullPath).isFile();
        if (isFile) {
            console.log(fullPath);
            if (!fs.existsSync(path.join(currpath,"organisedFiles"))) {
                fs.mkdirSync(path.join(__dirname, '../organisedFiles'));
            }
            let ext=path.extname(FilesArr[i]);
            let folder=getFolderName(ext);
            console.log(ext);
            let des=path.join(currpath,'organisedFiles',folder);
            // console.log(des);
            if(!fs.existsSync(des)){
                fs.mkdirSync(des);
            }
            // fs.renameSync(fullPath,des);
            fs.copyFileSync(fullPath,des);
        }
    }
}
function getFolderName(ext){
    for(let key in types){
        for(let i=0;i<types[key].length;i++){
            if(types[key][i]==ext){
                return key;
            }
        }
    }
    return "miscellaneous";
}
