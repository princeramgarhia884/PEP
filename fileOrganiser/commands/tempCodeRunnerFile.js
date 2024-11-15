h,fileArr[i]);
        if(fs.lstatSync(fullPath).isDirectory()){
            console.log(fileArr[i]);
            console.log('|-')
            // let newPath=path.join(fPath,fileArr[i]);
            rec(fullPath)
        }
        else{
            console.log(fileArr[i]);
        }
        
    }