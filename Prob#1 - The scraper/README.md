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
- beautifulSoup4
- chrome driver for window, linux, and macOS

> Web section

- UIkit3

## Objectives

1. Know concept of DOM structure.
2. Know some basic of HTTP request.
3. Know some basic of string manipulation.

## Ideas

- The main issue of this problem is how to scrape hidden elements which don't load on the first visit.
- To solve the issue, I decide to use automation testing to open all Baan's size for loading all Baan's URLs.
- After that, scrape all Baan's URLs. Get a name and a slogan. Then, push them into the result array.
- After collecting all data, python will create new HTML tags. Place collected data, Baan's name, and slogan, to the new element.
- Create a DOM tree with bs4 and append to `table-body` which is `tbody` of the HTML template.
