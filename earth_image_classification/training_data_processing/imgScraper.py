""" SSI Satellites
    Katie Mishra | February 2019
    Using image links from landsat csv, scrape images and put them in a folder. """

import urllib.request
import csv

# Scrape image from url
def downloader(image_url, file_path):
    urllib.request.urlretrieve(image_url,file_path)

link_array = ["https://earthexplorer.usgs.gov/browse-link/13400/LC81561192017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560212017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81561212017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560182017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030502017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030132017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030122017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030142017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560202017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030542017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030612017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030162017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030672017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560112017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560172017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030592017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030602017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030622017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030512017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030182017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030472017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030492017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030522017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030532017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030172017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030552017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030582017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81721182017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81721092017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81721122017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560432017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030252017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030632017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560402017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81721162017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81721202017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560132017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030662017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560262017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560122017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030702017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560222017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560232017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560252017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560162017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560312017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560382017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81721152017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80031112017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC82040192017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81390262015362LGN02",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81401202017038LGN01",
"https://earthexplorer.usgs.gov/browse-link/13400/LC82040232017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC82041162017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560362017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81881192017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC82200772016148LGN02",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560352017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC82201072017086LGN01",
"https://earthexplorer.usgs.gov/browse-link/13400/LC82201082017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81881202017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81721222017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC82041142017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC82040282017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030722017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560242017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560292017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030272017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81561092017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030262017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80031152017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC82040442017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80031122017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81721102017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030712017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC82040432017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81721172017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560272017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81880152017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81880162017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80030282017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC82040402017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560302017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81721112017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81721212017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC81560632017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC82201062017038LGN00",
"https://earthexplorer.usgs.gov/browse-link/13400/LC80031212017038LGN00"]
dataset_prefix = "LC8"


# Prepare variables to pass to downloader
#image_url = "https://earthexplorer.usgs.gov/browse-link/13400/LC81561192017038LGN00"


for image_url in link_array:
    file_name = image_url[image_url.find(dataset_prefix):len(image_url)-1] + ".jpg"
    file_path = "/Users/katiemishra/Desktop/sats-cs/earth_image_classification/training_data_processing/Images/" + file_name
    downloader(image_url, file_path)
