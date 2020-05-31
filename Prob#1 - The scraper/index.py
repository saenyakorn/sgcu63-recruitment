import os
import time
import json
from selenium import webdriver
from bs4 import BeautifulSoup

def clearContent():
    # clear table.html content
    with open(os.path.abspath("Prob#1 - The scraper/website/table.html"), "w", encoding="utf-8") as html:
        html.write("")
    print("clear content successful")

def scrapingRubnongkaomai():
    defalut_url = "https://rubnongkaomai.com/baan/"

    # chrome driver path
    driver_window_path = os.path.abspath("Prob#1 - The scraper/driver/window/chromedriver.exe")
    driver_linux_path = os.path.abspath("Prob#1 - The scraper/driver/linux/chromedriver")
    driver_macOS_path = os.path.abspath("Prob#1 - The scraper/driver/macOS/chromedriver")

    # get the content of the interested website (run on chrome browser only)
    selected_driver = [driver_window_path, driver_linux_path, driver_macOS_path]
    user_selection = int(input("Selected your OS 0-2 \n0) window \n1) linux\n2) macOS\n"))

    try:
        # load driver
        driver = webdriver.Chrome(selected_driver[user_selection])
        driver.maximize_window()
        driver.get(defalut_url)
        driver.set_page_load_timeout(10)

        # click all tabs to load all hidden elements
        tabs = driver.find_elements_by_xpath("//div[@role = 'tab']")
        for tab in tabs:
            print("Clicked " + tab.text)
            tab.click()

        # wait a moment 
        print("*********************\n*** On processing ***\n*********************")
        time.sleep(0.5)

        # get all Baan's url
        baan_cols = driver.find_elements_by_css_selector(".ant-col.ant-col-8")
        baan_url_collections = [
            element.find_element_by_tag_name("a").get_attribute("href")
            for element in baan_cols
        ]

        # enter to every Baan sites
        data_collections = []
        for baan_url in baan_url_collections:
            # load new site with Baan's url
            driver.get(baan_url)

            # init Baan data as object
            data_collections.append({"url": baan_url})

            while True:
                # get Baan name and push to the array
                baan_name = driver.find_element_by_xpath("//h1[@type='header']").text
                data_collections[-1]["name"] = baan_name

                # get Baan slogan and push to the array
                baan_slogan = driver.find_element_by_xpath("//h3[@type='header']").text
                data_collections[-1]["slogan"] = baan_slogan

                if(baan_name != None and baan_slogan != None): 
                    break

        # close the automation testing
        time.sleep(1)
        driver.close()

        # get html template
        html_template = open(os.path.abspath("Prob#1 - The scraper/website/template.html"), "r", encoding="utf-8")
        data = html_template.read()

        # get BeautifulSoup from the template and find table body for appending element
        soup = BeautifulSoup(data, "html.parser")
        table_body = soup.find(id="table-body")
        
        # append formated element to the soup
        for i in range(len(data_collections)):
            # get formated data
            name = data_collections[i]["name"].strip()
            slogan = data_collections[i]["slogan"].strip()
            url = baan_url_collections[i].strip()

            # define node 
            contaienr_row = soup.new_tag("tr")
            order_cell = soup.new_tag("td")
            name_cell = soup.new_tag("td")
            slogan_cell = soup.new_tag("td")
            url_cell = soup.new_tag("td")
            url_cell_button = soup.new_tag("a", href="{}".format(url))
            url_cell_button["class"] = "uk-button uk-button-default"

            # aet value 
            order_cell.string = str(i)
            name_cell.string = name
            slogan_cell.string = slogan
            url_cell_button.string = "Link"

            # create a tree
            url_cell.append(url_cell_button)
            [contaienr_row.append(tag) for tag in [order_cell,name_cell,slogan_cell,url_cell]]
            table_body.append(contaienr_row)

        # place edited html to table.html
        with open(os.path.abspath("Prob#1 - The scraper/website/table.html"), "w", encoding="utf-8") as html:
            html.write(soup.prettify())

        # end of the program
        print("success")
    except:
        print("Error")

if __name__ == "__main__":
    choice = input("Selected your option\n0) clear table.html content \n1) scrape rubnongkaomai.com\n")
    if choice == "0" :
        clearContent()
    elif choice == "1": 
        scrapingRubnongkaomai()
    else:
        print("Error")

