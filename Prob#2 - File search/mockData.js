fileSearch = require("./index.js")

var mockData = {
  FolderA: {
    _file: ["file1", "file2"],
    SubfolderC: {
      _file: ["file1"]
    },
    SubfolderB: {
      _file: ["file1"]
    }
  }
}

result = fileSearch("file1", mockData)
console.log(result)
