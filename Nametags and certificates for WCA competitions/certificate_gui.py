import PIL.Image
import PIL.ImageDraw
import PIL.ImageFont
from bs4 import BeautifulSoup
import requests
from tkinter import *
import textwrap

def show_example():
    all_good = True
    global URL, image, font
    if URL_input.get():
        if "https://" in URL_input.get():
            URL = URL_input.get()
        else:
            name = URL_input.get().replace(" ", "").replace("'", "").replace("&", "").replace("-", "")
            URL = f"https://www.worldcubeassociation.org/competitions/{name}"
    else:
        all_good = False
    if image_input.get():
        image = image_input.get()
    else:
        all_good = False
    if font_input.get():
        font = font_input.get()
    else:
        all_good = False
    if all_good:
        get_data()
        preview()


def button_export():
    global URL, image, font
    if URL_input.get():
        if "https://" in URL_input.get():
            URL = URL_input.get()
        else:
            name = URL_input.get().replace(" ", "").replace("'", "").replace("&", "").replace("-", "")
            URL = f"https://www.worldcubeassociation.org/competitions/{name}"
    if image_input.get():
        image = image_input.get()
    if font_input.get():
        font = font_input.get()
    get_data()
    export()


def gui():
    global URL_input, image_input, font_input, check_national, title_input, general_input, event_input, nat_input, title_size, general_size, event_size, place_size, place_input

    window = Tk()
    window.title("WCA Certificate Maker")
    window.minsize(600, 400)
    window.config(padx=10, pady=10)

    main_name = Label(text = "WCA Certificate Maker")
    main_name.grid(column=1, row=1, columnspan=3)

    space = Label(text="")
    space.grid(column=1, row=2)

    URL_text = Label(text = "Competition name or url: ")
    URL_text.grid(column=1, row=3)

    URL_input = Entry(width=30)
    URL_input.grid(column=2, row=3, columnspan=2)

    image_text = Label(text = "Picture name (with extension .png or .jpg): ")
    image_text.grid(column=1, row=4)

    image_input = Entry(width=30)
    image_input.grid(column=2, row=4, columnspan=2)

    font_text = Label(text = "Font name (with extension .ttf): ")
    font_text.grid(column=1, row=5)

    font_input = Entry(width=30)
    font_input.grid(column=2, row=5, columnspan=2)

    title_text = Label(text = "Title position: ")
    title_text.grid(column=1, row=6)

    title_input = Entry(width=30)
    title_input.grid(column=2, row=6, columnspan=2)
    title_input.insert(0, -320)

    title_text1 = Label(text = "Title size: ")
    title_text1.grid(column=1, row=7)

    title_size = Entry(width=30)
    title_size.grid(column=2, row=7, columnspan=2)
    title_size.insert(0, 160)

    general_text = Label(text = "Main text position: ")
    general_text.grid(column=1, row=8)

    general_input = Entry(width=30)
    general_input.grid(column=2, row=8, columnspan=2)
    general_input.insert(0, -100)

    general_text1 = Label(text = "Main text size: ")
    general_text1.grid(column=1, row=9)

    general_size = Entry(width=30)
    general_size.grid(column=2, row=9, columnspan=2)
    general_size.insert(0, 60)

    event_text = Label(text = "Event text position: ")
    event_text.grid(column=1, row=10)

    event_input = Entry(width=30)
    event_input.grid(column=2, row=10, columnspan=2)
    event_input.insert(0, 200)

    event_text1 = Label(text = "Event text size: ")
    event_text1.grid(column=1, row=11)

    event_size = Entry(width=30)
    event_size.grid(column=2, row=11, columnspan=2)
    event_size.insert(0, 55)

    place_text = Label(text = "Place text position: ")
    place_text.grid(column=1, row=12)

    place_input = Entry(width=30)
    place_input.grid(column=2, row=12, columnspan=2)
    place_input.insert(0, 280)

    place_text1 = Label(text = "Place text size: ")
    place_text1.grid(column=1, row=13)

    place_size = Entry(width=30)
    place_size.grid(column=2, row=13, columnspan=2)
    place_size.insert(0, 50)

    space1 = Label(text="")
    space1.grid(column=1, row=14, columnspan=3)

    nat_text = Label(text = "Nation (if you want certificates for national podiums): ")
    nat_text.grid(column=1, row=15)

    nat_input = Entry(width=30)
    nat_input.grid(column=2, row=15, columnspan=2)

    space2 = Label(text="")
    space2.grid(column=1, row=16, columnspan=3)

    show_example_button = Button(text="Show example", command = show_example)
    show_example_button.grid(column=1, row=17)

    export = Button(text="Export", command = button_export)
    export.grid(column=2, row=17)

    window.mainloop()


def get_data():
    global fontmain, fonttext, fontevent, fontplace, nation, delegates, organizers, events, place, general_text, comp_name
    #fonts
    try:
        fontmain = PIL.ImageFont.truetype(font, int(title_size.get()))
        fonttext = PIL.ImageFont.truetype(font, int(general_size.get()))
        fontevent = PIL.ImageFont.truetype(font, int(event_size.get()))
        fontplace = PIL.ImageFont.truetype(font, int(place_size.get()))
    except AttributeError:
        pass
    else:
        #get site
        try:
            response = requests.get(URL)
            html = response.text
            soup = BeautifulSoup(html, "html.parser")
        except AttributeError:
            pass
        else:
            #competition name
            comp_name = soup.find("h3").getText().strip()

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
            try:
                all_delegates = soup.find("dt", text="WCA Delegates").findNext("dd")
            except:
                all_delegates = soup.find("dt", text="WCA Delegate").findNext("dd")

            delegates = [name.getText().replace("\n", "").strip() for name in all_delegates]
            delegates = [name for name in delegates if name != "" and "and" not in name and "," not in name]

            #get all organizers except delegates
            try:
                all_organizers = soup.find("dt", text="Organizers").findNext("dd")
            except:
                all_organizers = soup.find("dt", text="Organizer").findNext("dd")
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

            general_text = f"{start}, on behalf of the world cube association, and {org} on behalf of the organization team of {comp_name} certify that"

            new_text = textwrap.wrap(general_text, width=70)
            general_text = ""
            for el in new_text:
                general_text += el + "\n"

            place = f"{city} - {date}"


def preview():
    try:
        img = PIL.Image.open(image)
        draw = PIL.ImageDraw.Draw(img)
    except AttributeError:
        pass
    else:
        x, y = img.size
        num = "1ST"
        event_text = f"HAS PLACED {num} AT THE EVENT OF {events[0]}"
        draw.text((x/2, y/2 + int(title_input.get())), comp_name.upper(), font=fontmain, fill=(0, 0, 0), anchor="mm")
        draw.text((x/2, y/2 + int(general_input.get())), general_text.upper(), font=fonttext, fill=(0, 0, 0), anchor="mm", align="center")

        if not nat_input.get():
            draw.text((x/2, y/2 + int(place_input.get())), place.upper(), font=fontplace, fill=(0, 0, 0), anchor="mm")
            draw.text((x/2, y/2 + int(event_input.get())), event_text.upper(), font=fontevent, fill=(0, 0, 0), anchor="mm")
        else:
            ### for national podiums
            text = event_text + "\n" + f"AMONG {nat_input.get().upper()} COMPETITORS"
            draw.text((x/2, y/2 + int(event_input.get())), text.upper(), font=fontevent, fill=(0, 0, 0), anchor="mm", align="center")
            draw.text((x/2, y/2 + int(place_input.get())), place.upper(), font=fontplace, fill=(0, 0, 0), anchor="mm")
        
        img.show()


def export():
    for event in events:
        for i in range(1,4):
            img = PIL.Image.open(image)
            draw = PIL.ImageDraw.Draw(img)
            x, y = img.size
            num = ""
            if i == 1:
                num = "1ST"
            elif i == 2:
                num = "2ND"
            else:
                num = "3RD"
            event_text = f"HAS PLACED {num} AT THE EVENT OF {event}"
            draw.text((x/2, y/2 + int(title_input.get())), comp_name.upper(), font=fontmain, fill=(0, 0, 0), anchor="mm")
            draw.text((x/2, y/2 + int(general_input.get())), general_text.upper(), font=fonttext, fill=(0, 0, 0), anchor="mm", align="center")
            draw.text((x/2, y/2 + int(event_input.get())), event_text.upper(), font=fontevent, fill=(0, 0, 0), anchor="mm")

            if not nat_input.get():
                draw.text((x/2, y/2 + int(place_input.get())), place.upper(), font=fontplace, fill=(0, 0, 0), anchor="mm")
                draw.text((x/2, y/2 + int(event_input.get())), event_text.upper(), font=fontevent, fill=(0, 0, 0), anchor="mm")
            else:
                ### for national podiums
                text = event_text + "\n" + f"AMONG {nat_input.get().upper()} COMPETITORS"
                draw.text((x/2, y/2 + int(event_input.get())), text.upper(), font=fontevent, fill=(0, 0, 0), anchor="mm", align="center")
                draw.text((x/2, y/2 + int(place_input.get())), place.upper(), font=fontplace, fill=(0, 0, 0), anchor="mm")

            filename = event.replace(" ", "")
            img.save(f"{i}_{filename}.png")

gui()