from PIL import Image, ImageDraw, ImageFont
from bs4 import BeautifulSoup
import requests

### HOW TO USE
# Copy the link of the competition page and put it in URL variable
# Put picture of blank name tag in the same folder as this file and write file name in image variable
# Download any font and put it in the same folder as this file and put name in font variable

####
URL = "https://www.worldcubeassociation.org/competitions/SerbianChampionship2022"
image = "modla.jpg"
font = "BebasNeue.ttf"
####

URL_reg = f"{URL}/registrations"

#delegates or organizers
response = requests.get(URL)
html = response.text

soup = BeautifulSoup(html, "html.parser")

#get all delegates
all_delegates = soup.find("dt", text="WCA Delegates").findNext("dd")
delegates = [name.getText().replace("\n", "").strip() for name in all_delegates]
delegates = [name for name in delegates if name != "" and "and" not in name and "," not in name]

#get all organizers except delegates
all_organizers = soup.find("dt", text="Organizers").findNext("dd")
organizers = [name.getText().replace("\n", "").strip() for name in all_organizers]
organizers = [name for name in organizers if name != "" and "and" not in name and "," not in name and name not in delegates]


#dobavljenje imena i drzava
response = requests.get(URL_reg)
html = response.text

soup = BeautifulSoup(html, "html.parser")
all_names = soup.findAll(class_ = "name")
names = [name.getText().replace("\n", "").strip() for name in all_names]
names = names[1:]

all_countries = soup.find_all(class_ = "country")
countries = [country.getText().replace("\n", "").strip() for country in all_countries]
countries = countries[1::]

#pisanje
fontname = ImageFont.truetype(font, 150)
fontcountry = ImageFont.truetype(font, 120)

for i in range(len(names)):
    img = Image.open(image)
    draw = ImageDraw.Draw(img)
    x, y = img.size

    draw.text((x/2, y/2 + 150), countries[i], font=fontcountry, fill=(0, 0, 0), anchor="mm")
    draw.text((x/2, y/2), names[i], font=fontname, fill=(0, 0, 0), anchor="mm")
    if names[i] in delegates:
        draw.text((x/2, y/2 + 350), "delegate", font=fontcountry, fill=(204, 0, 0), anchor="mm")
    elif names[i] in organizers:
        draw.text((x/2, y/2 + 350), "organizer", font=fontcountry, fill=(0, 153, 255), anchor="mm")
    else:
        draw.text((x/2, y/2 + 350), "competitor", font=fontcountry, fill=(0, 204, 102), anchor="mm")

    #preview
    img.show()

    #save
    # filename = names[1].replace(" ", "")
    # img.save(f"{filename}.png")