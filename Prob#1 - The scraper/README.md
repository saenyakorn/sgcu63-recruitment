# Prob#1 - The scraper

sgcu63 recruitment's problem number 1

## Table of contents

- [Project Dependencies](projectdependencies)
- [Objectives](objectives)
- [Ideas](ideas)

## Project Dependencies

> Python Section

- time
- json
- selenium
- chrome driver for window, linux, and macOS

> Web section

- UIkit3
- jQuery

## Objectives

1. Know concept of DOM structure.
2. Know some basic of HTTP request.
3. Know some basic of string manipulation.

## Ideas

- The main issue of this problem is how to scrape hidden elements which don't load on the first visit
- To solve the issue, I decide to use automation testing to open all Baan's size for loading all Baan's URLs
- After that, scrape all Baan's URLs. Get a name and a slogan. Then, push them into the result array
- Export the result to JSON file, named export_data.json
- table.html will read export_data.json and will be displayed in the browser
