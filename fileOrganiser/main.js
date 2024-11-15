// const help = require("./commands/help");
// const organise = require("./commands/organise");
// const tree = require("./commands/tree");
const path = require("path");
const fs = require("fs");
// let input=process.argv.slice(2);
// let command=input[0];
// let path = inputArr[1];
// switch (command) {
//     case "tree":
//         console.log("tree");
//         break;
//     case "organise":
//         console.log("organise");
//         break;
//     case "help":
//         help.help();
//         break;    
//     default:
//         console.log("please enter valid input");
// }
console.log(__dirname);
fs.copyFileSync(path.join(__dirname,'file.txt'),path.join(__dirname,'file2.txt'));
fs.unlinkSync(path.join(__dirname,'file.txt'));