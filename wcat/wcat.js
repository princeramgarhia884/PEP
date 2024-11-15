const fs = require("fs");
let input = process.argv;
let fileArr = [];
let optionsArr = [];
for (let i = 2; i < input.length; i++) {
    if (input[i].charAt(0) == "-") {
        optionsArr.push(input[i]);
    }
    else {
        fileArr.push(input[i]);
    }
}
console.log(optionsArr);
console.log(fileArr);
for (let i = 0; i < fileArr.length; i++) {
    if (!fs.existsSync(fileArr[i])) return false;
}
let content = "";
for (let i = 0; i < fileArr.length; i++) {
    let ans = fs.readFileSync(fileArr[i]);
    content += ans;
}
let contentArr = content.split("\n"); 
console.table(contentArr);

//check if -s is present or not
let tempArr = [];
let isSPresent = optionsArr.includes("-s");
if (isSPresent) {
    for (let i = 1; i < contentArr.length; i++) {
        if (contentArr[i] == "" && (contentArr[i - 1] == "" ||contentArr[i - 1] == null)) {
            contentArr[i] = null;
        }
        // else if (contentArr[i] == "" && contentArr[i - 1] == null) {
        //     contentArr[i] = null;
        // }
    }
    console.table(contentArr);
}
