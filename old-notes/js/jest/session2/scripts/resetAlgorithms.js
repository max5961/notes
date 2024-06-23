const fs = require('fs');
const path = require('path');

const algorithmsDir = path.join(__dirname, '../src/algorithms');

fs.readdir(algorithmsDir, (err, files) => {
  if (err) {
    console.error('Unable to read directory contents:', err);
    return;
  }

  files.forEach(file => {
    const filePath = path.join(algorithmsDir, file);
    const content = fs.readFileSync(filePath, 'utf8');

    // This regex matches function declarations and arrow functions and clears their content.
    const clearedContent = content.replace(/(function \w+\(.*\)|\w+ = \(.*\)\s*=>)\s*{[^}]*}/g, '$1 => {}');

    fs.writeFileSync(filePath, clearedContent);
  });

  console.log("Algorithm function contents have been cleared!");
});


