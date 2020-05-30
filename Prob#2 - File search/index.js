var allPath = new Array()

function depthFirstSearch(fileToSearch, filesObj, path = "/") {
  // sort fileObject by key and copy it to orderObj
  orderedObj = {}
  Object.keys(filesObj)
    .sort()
    .forEach(key => {
      orderedObj[key] = filesObj[key]
    })

  // find desired file first
  files = orderedObj["_file"]
  if (files != null) {
    files.forEach(element => {
      element == fileToSearch ? allPath.push(path + "/" + fileToSearch) : null
    })
  }

  // enter to the next
  Object.entries(orderedObj).forEach(([key, val]) => {
    key != "_file" ? depthFirstSearch(fileToSearch, val, path + "/" + key) : null
  })
}

module.exports = function fileSearch(fileToSearch, filesObj) {
  allPath = new Array()
  depthFirstSearch(fileToSearch, filesObj)
  return allPath
}
