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


#get names, countries, ids
response = requests.get(URL_reg)
html = response.text

soup = BeautifulSoup(html, "html.parser")

#competition name
comp_name = soup.find("h3").getText().strip()
nation = comp_name.split(" ")[0]

#get all names
all_names = soup.find_all(class_ = "name")
names = [name.getText().replace("\n", "").strip() for name in all_names]
names = names[1:]

#get ids
ids = []
for element in all_names:
    el = element.find("a")
    if el == None:
        ids.append("")
    else:
        id = el["href"].split("/")[-1]
        ids.append(id)
ids = ids[1::]

#get all countries
all_countries = soup.find_all(class_ = "country")
countries = [country.getText().replace("\n", "").strip() for country in all_countries]
countries = countries[1::]


flags_dict = {}
#flags
for el in list(dict.fromkeys(countries)):
    response = requests.get(f"https://en.wikipedia.org/wiki/{el}")
    html = response.text
    soup = BeautifulSoup(html, "html.parser")
    link = soup.find("img", {"alt": f"Flag of {el}"})["src"]
    flags_dict[el] = f"https:{link}"

#fonts
fontname = ImageFont.truetype(font, 150)
fontcountry = ImageFont.truetype(font, 120)
fontid = ImageFont.truetype(font, 100)
fontmain = ImageFont.truetype(font, 120)

for i in range(len(names)):
    img = Image.open(image)
    x, y = img.size

    #flag
    for key, value in flags_dict.items():
        if key == countries[i]:
            flag_img = Image.open(requests.get(value, stream=True).raw)
            x_new, y_new = flag_img.size
            img.paste(flag_img, (int((x-x_new)/2), int(y/2 + 100)))

    draw = ImageDraw.Draw(img)

    #comp name
    #draw.text((x/2, y/2 - 340), comp_name, font=fontmain, fill=(255, 255, 255), anchor="mm")

    #name
    draw.text((x/2, y/2), names[i], font=fontname, fill=(0, 0, 0), anchor="mm")

    #country text
    #draw.text((x/2, y/2 + 150), countries[i], font=fontcountry, fill=(0, 0, 0), anchor="mm")

    #id
    #draw.text((x/2, y/2 + 150), ids[i], font=fontid, fill=(0, 0, 0), anchor="mm")


    #competitor, delegate or organizer
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