const path=require("path");
const fs=require("fs");
let folderPath='C:\\Users\\prince\\Desktop\\PEP\\fileOrganiser';
function rec(fPath,level){
    console.log(level+"└──"+path.basename(fPath));
    let fileArr=fs.readdirSync(fPath);
    for(let i=0;i<fileArr.length;i++){
        let fullPath=path.join(fPath,fileArr[i]);
        if(fs.lstatSync(fullPath).isDirectory()){
            console.log(level +"├── "+fileArr[i]);
            rec(fullPath,level+"\t");
        }
        else{
            console.log(level+"└──"+fileArr[i]);
        }  
    }
}
rec(folderPath," ");


// const fs = require("fs");
// const path = require("path");

// function treeFn(dirPath) {
//   if (dirPath == undefined) {
//     console.log("Please Enter a Valid Path");
//     return;
//   }
//   let doesExist = fs.existsSync(dirPath);
//   if (doesExist == true) {
//     treeHelper(dirPath, " ");
//   }
// }

// function treeHelper(targetPath, indent) {
//     let isFile = fs.lstatSync(targetPath).isFile();

//     if (isFile == true) {
//         let fileName = path.basename(targetPath);
//         console.log(indent + "├── " + fileName);
//         return;
//     }
//     let dirName = path.basename(targetPath);
//     console.log(indent + "└──" + dirName);

//     let children = fs.readdirSync(targetPath);

//     for (let i = 0; i < children.length; i++) {
//       let childpath = path.join(targetPath, children[i]);
//       treeHelper(childpath, indent + "\t");
//     }
// }

// treeFn(folderPath);