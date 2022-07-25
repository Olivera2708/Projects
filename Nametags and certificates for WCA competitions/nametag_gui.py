import PIL.Image
import PIL.ImageDraw
import PIL.ImageFont
from bs4 import BeautifulSoup
import requests
from tkinter import *


def show_example():
    global URL_reg

    all_good = True
    global URL, image, font
    if URL_input.get():
        if "https://" in URL_input.get():
            URL = URL_input.get()
        else:
            name = URL_input.get().replace(" ", "").replace("'", "").replace("&", "").replace("-", "")
            URL = f"https://www.worldcubeassociation.org/competitions/{name}"
        URL_reg = f"{URL}/registrations"
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
    global URL_reg

    global URL, image, font
    if URL_input.get():
        if "https://" in URL_input.get():
            URL = URL_input.get()
        else:
            name = URL_input.get().replace(" ", "").replace("'", "").replace("&", "").replace("-", "")
            URL = f"https://www.worldcubeassociation.org/competitions/{name}"
        URL_reg = f"{URL}/registrations"
    if image_input.get():
        image = image_input.get()
    if font_input.get():
        font = font_input.get()
    get_data()
    export()

def gui():
    global URL_input, image_input, font_input, comp_name, flag_c, country_c, wcaid_c, type_c, comp_input, comp_size, comp_b, comp_g, comp_r
    global pers_input, pers_size, flag_input_x, flag_input_y, country_input, country_size, wcaid_input, wcaid_size, type_input, type_size, have_name_comp
    global pers_g, pers_r, pers_b, coun_b, coun_g, coun_r, type_r, type_g, type_b, wca_r, wca_g, wca_b, delegate_p, organizer_p, competitor_p

    window = Tk()
    window.title("WCA Name Tag Maker")
    window.minsize(600, 500)
    window.config(padx=10, pady=10)

    main_name = Label(text = "WCA Name Tag Maker")
    main_name.grid(column=1, row=1, columnspan=5)

    space = Label(text="")
    space.grid(column=1, row=2)

    have_name_comp = IntVar()
    C6 = Checkbutton(text = "Competition name or url: ", variable = have_name_comp, \
                     onvalue = 1, offvalue = 0)
    C6.grid(column=1, row=3)

    URL_input = Entry(width=30)
    URL_input.grid(column=2, row=3, columnspan=3)

    image_text = Label(text = "Picture name (with extension .png or .jpg): ")
    image_text.grid(column=1, row=4)

    image_input = Entry(width=30)
    image_input.grid(column=2, row=4, columnspan=3)

    font_text = Label(text = "Font name (with extension .ttf): ")
    font_text.grid(column=1, row=5)

    font_input = Entry(width=30)
    font_input.grid(column=2, row=5, columnspan=3)

    space = Label(text="")
    space.grid(column=1, row=6)

    comp_text = Label(text = "Competition text position: ")
    comp_text.grid(column=1, row=7)

    comp_input = Entry(width=5)
    comp_input.grid(column=2, row=7)
    comp_input.insert(0, -340)

    comp1_text = Label(text = "Competition text size: ")
    comp1_text.grid(column=3, row=7)

    comp_size = Entry(width=5)
    comp_size.grid(column=4, row=7)
    comp_size.insert(0, 120)

    comp2_text = Label(text = "Competition text color (R, G, B): ")
    comp2_text.grid(column=1, row=8)

    comp_r = Entry(width=10)
    comp_r.grid(column=2, row=8)
    comp_r.insert(0, 255)

    comp_g = Entry(width=10)
    comp_g.grid(column=3, row=8)
    comp_g.insert(0, 255)

    comp_b = Entry(width=10)
    comp_b.grid(column=4, row=8)
    comp_b.insert(0, 255)

    space1 = Label(text="")
    space1.grid(column=1, row=9)

    pers_text = Label(text = "Name text position: ")
    pers_text.grid(column=1, row=10)

    pers_input = Entry(width=5)
    pers_input.grid(column=2, row=10)
    pers_input.insert(0, 0)

    pers1_text = Label(text = "Name text size: ")
    pers1_text.grid(column=3, row=10)

    pers_size = Entry(width=5)
    pers_size.grid(column=4, row=10)
    pers_size.insert(0, 150)

    pers2_text = Label(text = "Name text color (R, G, B): ")
    pers2_text.grid(column=1, row=11)

    pers_r = Entry(width=10)
    pers_r.grid(column=2, row=11)
    pers_r.insert(0, 0)

    pers_g = Entry(width=10)
    pers_g.grid(column=3, row=11)
    pers_g.insert(0, 0)

    pers_b = Entry(width=10)
    pers_b.grid(column=4, row=11)
    pers_b.insert(0, 0)

    space2 = Label(text="")
    space2.grid(column=1, row=12)

    country_c = IntVar()
    flag_c = IntVar()
    wcaid_c = IntVar()
    type_c = IntVar()
    C1 = Checkbutton(text = "Flag", variable = flag_c, \
                     onvalue = 1, offvalue = 0)
    C2 = Checkbutton(text = "Country", variable = country_c, \
                     onvalue = 1, offvalue = 0)
    C3 = Checkbutton(text = "WCA ID", variable = wcaid_c, \
    onvalue = 1, offvalue = 0)
    C4 = Checkbutton(text = "Competitor type", variable = type_c, \
                     onvalue = 1, offvalue = 0)
    C1.grid(column=1, row=13)
    C2.grid(column=1, row=14)
    C3.grid(column=1, row=16)
    C4.grid(column=1, row=18)

    flag_text = Label(text = "Flag position (x): ")
    flag_text.grid(column=2, row=13)

    flag_input_x = Entry(width=5)
    flag_input_x.grid(column=3, row=13)
    flag_input_x.insert(0, 0)

    flag_text = Label(text = "Flag position (y): ")
    flag_text.grid(column=4, row=13)

    flag_input_y = Entry(width=5)
    flag_input_y.grid(column=5, row=13)
    flag_input_y.insert(0, 100)

    country_text = Label(text = "Country name position: ")
    country_text.grid(column=2, row=14)

    country_input = Entry(width=5)
    country_input.grid(column=3, row=14)
    country_input.insert(0, 150)

    country_text1 = Label(text = "Country name size: ")
    country_text1.grid(column=4, row=14)

    country_size = Entry(width=5)
    country_size.grid(column=5, row=14)
    country_size.insert(0, 120)

    coun2_text = Label(text = "Country text color (R, G, B): ")
    coun2_text.grid(column=1, row=15)

    coun_r = Entry(width=10)
    coun_r.grid(column=2, row=15)
    coun_r.insert(0, 0)

    coun_g = Entry(width=10)
    coun_g.grid(column=3, row=15)
    coun_g.insert(0, 0)

    coun_b = Entry(width=10)
    coun_b.grid(column=4, row=15)
    coun_b.insert(0, 0)

    wcaid_text = Label(text = "WCA ID position: ")
    wcaid_text.grid(column=2, row=16)

    wcaid_input = Entry(width=5)
    wcaid_input.grid(column=3, row=16)
    wcaid_input.insert(0, 150)

    wcaid_text1 = Label(text = "WCA ID size: ")
    wcaid_text1.grid(column=4, row=16)

    wcaid_size = Entry(width=5)
    wcaid_size.grid(column=5, row=16)
    wcaid_size.insert(0, 100)

    wca2_text = Label(text = "WCA ID text color (R, G, B): ")
    wca2_text.grid(column=1, row=17)

    wca_r = Entry(width=10)
    wca_r.grid(column=2, row=17)
    wca_r.insert(0, 0)

    wca_g = Entry(width=10)
    wca_g.grid(column=3, row=17)
    wca_g.insert(0, 0)

    wca_b = Entry(width=10)
    wca_b.grid(column=4, row=17)
    wca_b.insert(0, 0)

    type_text = Label(text = "Competitor type position: ")
    type_text.grid(column=2, row=18)

    type_input = Entry(width=5)
    type_input.grid(column=3, row=18)
    type_input.insert(0, 350)

    type_text1 = Label(text = "Competitor type size: ")
    type_text1.grid(column=4, row=18)

    type_size = Entry(width=5)
    type_size.grid(column=5, row=18)
    type_size.insert(0, 120)

    type2_text = Label(text = "Competitor type text color (R, G, B): ")
    type2_text.grid(column=1, row=19)

    type_r = Entry(width=10)
    type_r.grid(column=2, row=19)
    type_r.insert(0, 0)

    type_g = Entry(width=10)
    type_g.grid(column=3, row=19)
    type_g.insert(0, 0)

    type_b = Entry(width=10)
    type_b.grid(column=4, row=19)
    type_b.insert(0, 0)

    space3 = Label(text="")
    space3.grid(column=1, row=20)

    text123 = Label(text="Nametags for: ")
    text123.grid(column=1, row=21)

    delegate_p = IntVar()
    organizer_p = IntVar()
    competitor_p = IntVar()
    C1 = Checkbutton(text = "Delegate", variable = delegate_p, \
                     onvalue = 1, offvalue = 0)
    C2 = Checkbutton(text = "Organizer", variable = organizer_p, \
                     onvalue = 1, offvalue = 0)
    C3 = Checkbutton(text = "Competitor", variable = competitor_p, \
    onvalue = 1, offvalue = 0)
    C1.grid(column=2, row=21)
    C2.grid(column=3, row=21)
    C3.grid(column=4, row=21)

    space2 = Label(text="")
    space2.grid(column=1, row=22)

    show_example_button = Button(text="Show example", command = show_example)
    show_example_button.grid(column=2, row=23)

    export = Button(text="Export", command = button_export)
    export.grid(column=3, row=23)

    window.mainloop()

def get_data():
    global organizers, delegates, countries, flags_dict, names, ids, comp_name

    #delegates or organizers
    response = requests.get(URL)
    html = response.text

    soup = BeautifulSoup(html, "html.parser")

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

    if flag_c.get() == 1:
        flags_dict = {}
        #flags
        for el in list(dict.fromkeys(countries)):
            response = requests.get(f"https://en.wikipedia.org/wiki/{el}")
            html = response.text
            soup = BeautifulSoup(html, "html.parser")
            try:
                link = soup.find("img", {"alt": f"Flag of {el}"})["src"]
            except:
                try:
                    link = soup.find("img", {"alt": f"Flag of the {el}"})["src"]
                except:
                    link = soup.find("a", {"title": f"Flag of {el}"}).find("img")["src"]
            flags_dict[el] = f"https:{link}"

def preview():
    #fonts
    fontname = PIL.ImageFont.truetype(font, int(pers_size.get()))
    fontcountry = PIL.ImageFont.truetype(font, int(country_size.get()))
    fontid = PIL.ImageFont.truetype(font, int(wcaid_size.get()))
    fontmain = PIL.ImageFont.truetype(font, int(comp_size.get()))
    fonttype = PIL.ImageFont.truetype(font, int(type_size.get()))

    img = PIL.Image.open(image)
    x, y = img.size

    #flag
    if flag_c.get() == 1:
        for key, value in flags_dict.items():
            if key == countries[0]:
                flag_img = PIL.Image.open(requests.get(value, stream=True).raw)
                x_new, y_new = flag_img.size
                img.paste(flag_img, (int((x-x_new)/2) + int(flag_input_x.get()), y//2 + int(flag_input_y.get())))
    draw = PIL.ImageDraw.Draw(img)

    #comp name
    if have_name_comp.get() == 1:
        colour = (int(comp_r.get()), int(comp_g.get()), int(comp_b.get()))
        draw.text((x//2, y//2 + int(comp_input.get())), comp_name.upper(), font=fontmain, fill=colour, anchor="mm")

    #name
    colour = (int(pers_r.get()), int(pers_g.get()), int(pers_b.get()))
    draw.text((x//2, y//2 + int(pers_input.get())), "John Doe", font=fontname, fill=colour, anchor="mm")

    #country text
    if country_c.get() == 1:
        colour = (int(coun_r.get()), int(coun_g.get()), int(coun_b.get()))
        draw.text((x//2, y//2 + int(country_input.get())), countries[0].upper(), font=fontcountry, fill=colour, anchor="mm")

    #id
    if wcaid_c.get() == 1:
        colour = (int(wca_r.get()), int(wca_g.get()), int(wca_b.get()))
        draw.text((x//2, y//2 + int(wcaid_input.get())), "2022ABC01", font=fontid, fill=colour, anchor="mm")

    #competitor, delegate or organizer
    if type_c.get() == 1:
        colour = (int(type_r.get()), int(type_g.get()), int(type_b.get()))
        if delegate_p.get() == 1:
            draw.text((x//2, y//2 + int(type_input.get())), "DELEGATE", font=fonttype, fill=colour, anchor="mm")
        elif organizer_p.get() == 1:
            draw.text((x//2, y//2 + int(type_input.get())), "ORGANIZER", font=fonttype, fill=colour, anchor="mm")
        else:
            draw.text((x//2, y//2 + int(type_input.get())), "COMPETITOR", font=fonttype, fill=colour, anchor="mm")
    #preview
    img.show()

def export():
    #fonts
    fontname = PIL.ImageFont.truetype(font, int(pers_size.get()))
    fontcountry = PIL.ImageFont.truetype(font, int(country_size.get()))
    fontid = PIL.ImageFont.truetype(font, int(wcaid_size.get()))
    fontmain = PIL.ImageFont.truetype(font, int(comp_size.get()))
    fonttype = PIL.ImageFont.truetype(font, int(type_size.get()))

    for i in range(len(names)):
        if delegate_p.get() == 1 and names[i] not in delegates:
            continue
        if organizer_p.get() == 1 and names[i] not in organizers:
            continue
        if competitor_p.get() == 1 and (names[i] in organizers or names[i] in delegates):
            continue

        img = PIL.Image.open(image)
        x, y = img.size

        #flag
        #flag
        if flag_c.get() == 1:
            for key, value in flags_dict.items():
                if key == countries[i]:
                    flag_img = PIL.Image.open(requests.get(value, stream=True).raw)
                    x_new, y_new = flag_img.size
                    img.paste(flag_img, (int((x-x_new)/2) + int(flag_input_x.get()), int(y/2) + int(flag_input_y.get())))
        draw = PIL.ImageDraw.Draw(img)

        #comp name
        if have_name_comp.get() == 1:
            colour = (int(comp_r.get()), int(comp_g.get()), int(comp_b.get()))
            draw.text((x/2, y/2 + int(comp_input.get())), comp_name.upper(), font=fontmain, fill=colour, anchor="mm")

        #name
        colour = (int(pers_r.get()), int(pers_g.get()), int(pers_b.get()))
        until = names[i].find("（");
        if until == -1:
            name_surname = names[i];
        else:
            name_surname = names[i][:until]
        draw.text((x/2, y/2 + int(pers_input.get())), name_surname, font=fontname, fill=colour, anchor="mm") #.upper()

        #country text
        if country_c.get() == 1:
            colour = (int(coun_r.get()), int(coun_g.get()), int(coun_b.get()))
            draw.text((x/2, y/2 + int(country_input.get())), countries[i].upper(), font=fontcountry, fill=colour, anchor="mm")

        #id
        if wcaid_c.get() == 1:
            colour = (int(wca_r.get()), int(wca_g.get()), int(wca_b.get()))
            draw.text((x/2, y/2 + int(wcaid_input.get())), ids[i].upper(), font=fontid, fill=colour, anchor="mm")

        #competitor, delegate or organizer
        if type_c.get() == 1:
            colour = (int(type_r.get()), int(type_g.get()), int(type_b.get()))
            if names[i] in delegates:
                draw.text((x/2, y/2 + int(type_input.get())), "DELEGATE", font=fonttype, fill=colour, anchor="mm")
            elif names[i] in organizers:
                draw.text((x/2, y/2 + int(type_input.get())), "ORGANIZER", font=fonttype, fill=colour, anchor="mm")
            else:
                draw.text((x/2, y/2 + int(type_input.get())), "COMPETITOR", font=fonttype, fill=colour, anchor="mm")
        
        filename = names[i].replace(" ", "")
        img.save(f"{filename}.png", dpi=(300,300))

gui()