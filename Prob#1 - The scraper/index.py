import time
import json
from selenium import webdriver

# interested url
defalut_url = "https://rubnongkaomai.com/" + "baan/"

# get the content of the wanted scraping website (run on chrome browser on macOS)
driver = webdriver.Chrome("./Prob#1 - The scraper/driver/macOS/chromedriver")
driver.maximize_window()
driver.get(defalut_url)
driver.set_page_load_timeout(10)

# click all tabs to load all hidden elements
tabs = driver.find_elements_by_xpath("//div[@role = 'tab']")
for tab in tabs:
    print("Clicked " + tab.text)
    tab.click()

print("On processing please wait")
time.sleep(0.5)

# get all baan url
baan_cols = driver.find_elements_by_css_selector(".ant-col.ant-col-8")
baan_url_collections = [
    element.find_element_by_tag_name("a").get_attribute("href") for element in baan_cols
]

# enter to every baan site
data_collections = []
for baan_url in baan_url_collections:
    # load new site with baan url
    driver.get(baan_url)
    driver.set_page_load_timeout(50)

    # init baan data as object
    data_collections.append({"url": baan_url})

    # get baan name and push to the array
    baan_name = driver.find_element_by_xpath("//h1[@type='header']").text
    data_collections[-1]["name"] = baan_name

    # get baan slogan and push to the array
    baan_slogan = driver.find_element_by_xpath("//h3[@type='header']").text
    data_collections[-1]["slogan"] = baan_slogan

# close the automation testing
time.sleep(1)
driver.close()

for i in range(len(baan_url_collections)):
    print("{} {}".format(data_collections[i]["name"], data_collections[i]["slogan"]))

with open("./Prob#1 - The scraper/export_data.json", "w") as outfile:
    json.dump(data_collections, outfile)

print("success")
