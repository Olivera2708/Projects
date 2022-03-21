from PIL import Image, ImageDraw, ImageFont
from bs4 import BeautifulSoup
import requests

### HOW TO USE
# Copy the link of the competition page on the wca site and paste it in URL above
# Put blank certificate in the same folder as this file and put name in image variable
# Download any font and put it in the same folder as this file and put name in font variable

####
URL = "https://www.worldcubeassociation.org/competitions/SerbianChampionship2022"
image = "cert.jpg"
font = "BebasNeue.ttf"
####

#fonts
fontmain = ImageFont.truetype(font, 175)
fonttext = ImageFont.truetype(font, 50)
fontevent = ImageFont.truetype(font, 65)
fontplace = ImageFont.truetype(font, 50)

#get site
response = requests.get(URL)
html = response.text

soup = BeautifulSoup(html, "html.parser")

#competition name
comp_name = soup.find("h3").getText().strip()
nation = comp_name.split(" ")[0]

#place
city = soup.find("dt", text="City").findNext("dd").getText().split(",")[0]

#date
all_date = soup.find("dt", text="Date").findNext("dd").getText().strip().split(" ")
datu = all_date[0]
dat = all_date[-2].replace(",", "")
if datu.lower() == "jan":
    datu = "january"
elif datu.lower() == "feb":
    datu = "february"
elif datu.lower() == "mar":
    datu = "march"
elif datu.lower() == "apr":
    datu = "april"
elif datu.lower() == "jun":
    datu = "june"
elif datu.lower() == "jul":
    datu = "july"
elif datu.lower() == "aug":
    datu = "august"
elif datu.lower() == "sep":
    datu = "september"
elif datu.lower() == "oct":
    datu = "october"
elif datu.lower() == "nov":
    datu = "november"
elif datu == "dec":
    datu = "december"


if dat[-1] == "1" and (int(dat) < 10 or int(dat) > 20):
    dat += "st"
elif dat[-1] == "2" and (int(dat) < 10 or int(dat) > 20):
    dat += "nd"
elif dat[-1] == "3" and (int(dat) < 10 or int(dat) > 20):
    dat += "rd"
else:
    dat += "th"

date = f"{datu} {dat}, {all_date[-1]}."

#get all delegates
all_delegates = soup.find("dt", text="WCA Delegates").findNext("dd")
delegates = [name.getText().replace("\n", "").strip() for name in all_delegates]
delegates = [name for name in delegates if name != "" and "and" not in name and "," not in name]

#get all organizers except delegates
all_organizers = soup.find("dt", text="Organizers").findNext("dd")
organizers = [name.getText().replace("\n", "").strip() for name in all_organizers]
organizers = [name for name in organizers if name != "" and "and" not in name and "," not in name and name not in delegates]

#get events
all_events = soup.find_all("i", {"data-toggle": "tooltip", "data-placement": "top", "data-container": "body"})
events = [event["title"] for event in all_events[:-1]]

start = ""
num_delegates = len(delegates)
for el in range(num_delegates):
    start += delegates[el]
    if num_delegates - 1 == el:
        break
    if num_delegates - 2 == el:
        start += " and "
    else:
        start += ", "

org = ""
num_organizers = len(organizers)
for el in range(num_organizers):
    org += organizers[el]
    if num_organizers - 1 == el:
        break
    if num_organizers - 2 == el:
        org += " and "
    else:
        org += ", "

general_text = f'''{start}, on behalf of the world cube association,
and {org} on behalf of the organization
team of {comp_name} certify that'''

place = f"{city} - {date}"


for event in events:
    for i in range(1,4):
        img = Image.open(image)
        draw = ImageDraw.Draw(img)
        x, y = img.size
        num = ""
        if i == 1:
            num = "1st"
        elif i == 2:
            num = "2nd"
        else:
            num = "3rd"
        event_text = f"has placed {num} at the event of {event}"
        draw.text((x/2, y/2 - 300), comp_name, font=fontmain, fill=(0, 0, 0), anchor="mm")
        draw.text((x/2, y/2 - 100), general_text, font=fonttext, fill=(0, 0, 0), anchor="mm", align="center")
        draw.text((x/2, y/2 + 200), event_text, font=fontevent, fill=(0, 0, 0), anchor="mm")

        ### regualar
        draw.text((x/2, y/2 + 280), place, font=fontplace, fill=(0, 0, 0), anchor="mm")

        ### for national podiums
        # draw.text((x/2, y/2 + 260), f"among {nation} competitors", font=fontevent, fill=(0, 0, 0), anchor="mm")
        # draw.text((x/2, y/2 + 340), place, font=fontplace, fill=(0, 0, 0), anchor="mm")

        #preview
        img.show()

        #save
        # filename = event.replace(" ", "")
        # img.save(f"{i}_{filename}.png")
