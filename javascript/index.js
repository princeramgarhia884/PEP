const fs=require('fs');
const path=require('path');
// fs.appendFileSync('message2.txt',' hi how are you');
// fs.accessSync('message.txt',(err)=>{
    // console.log(err);
// })

// console.log(__dirname);
// fs.readFile('message2.txt', 'utf8', function(err, data){
      
//     // Display the file content
//     console.log(data);
// });
// let res=fs.readFileSync('message1.txt','utf8');
// console.log(res);
// console.log('readFile called');
// getCurrentFilenames();
// console.log(__dirname);
// fs.mkdir(path.join(__dirname,'newfolder'),{recursive:true},(err)=>{
//     if (err) {
//         return console.error(err);
//     }
//     console.log('Directory created successfully!');
// })
// fs.renameSync(path.join(__dirname,'changed_folder.txt'),path.join(__dirname,'message.txt'));
// fs.mkdirSync('newfolder');
// fs.rmdir('newfolder',{recursive:true},(err)=>{
//     if(err){
//         console.log(err);
//     }
//     else{
//         console.log("deleted");
//     }
// })

fs.statSync