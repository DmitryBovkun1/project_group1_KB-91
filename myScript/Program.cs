using System;
using System.Net;
using System.IO;
using System.Collections.Generic;
using Newtonsoft.Json;

namespace myScript
{
    public class Info
    {
        public string DATE_REG { get; set; }
        public string NAME_WDAY { get; set; }
        public string NAME_PAIR { get; set; }
        public string TIME_PAIR { get; set; }
        public string NAME_FIO { get; set; }
        public string NAME_AUD { get; set; }
        public string NAME_GROUP { get; set; }
        public string ABBR_DISC { get; set; }
        public string NAME_STUD { get; set; }
        public string REASON { get; set; }
        public string PUB_DATE { get; set; }
        public string KOD_STUD { get; set; }
        public string KOD_FIO { get; set; }
        public string KOD_AUD { get; set; }
        public string KOD_DISC { get; set; }
        public string INFO { get; set; }
        public string LATITUDE { get; set; }
        public string LONGITUDE { get; set; }
        public string NAME_DISC { get; set; }
        public string ID_TOKEN { get; set; }
    }

    class Program
    {
        public static List<Info> ToListJsonPairs(string jsonString)
        {
            List<Info> listPairs = JsonConvert.DeserializeObject<List<Info>>(jsonString);
            return listPairs;
        }
        static string CreateParamGetResponseSumDU(string start_day, string finish_day, string id_grp)
        {
            return "method=getSchedules&" + "id_grp=" + id_grp + "&id_fio=0&id_aud=0" + "&date_beg=" + start_day + "&date_end=" + finish_day;
        }
        static void GET(string url, string data, string choice)
        {
            WebRequest req = WebRequest.Create(url + "?" + data);
            string s = url + "?" + data;
            Console.WriteLine(s);
            WebResponse resp = req.GetResponse();
            Stream stream = resp.GetResponseStream();
            using (StreamReader sr = new StreamReader(stream))
            {
                string line;
                StreamWriter sw;
                if (choice == "1")
                {
                    sw = new StreamWriter("allDiscipline.html", false, System.Text.Encoding.Default);
                }
                else
                {
                    sw = new StreamWriter("allDiscipline.html", true, System.Text.Encoding.Default);
                }
                List<Info> myDeserializedClass = new List<Info> { };
                while ((line = sr.ReadLine()) != null)
                {
                    myDeserializedClass = ToListJsonPairs(line);          
                }
                foreach (Info a in myDeserializedClass)
                {
                    sw.WriteLine(a.NAME_DISC);
                    sw.WriteLine(a.NAME_GROUP);
                    sw.WriteLine(a.NAME_FIO);
                    sw.WriteLine(a.DATE_REG);
                    sw.WriteLine(a.NAME_AUD);
                }
                sw.Close();
            }
        }
        static void Main()
        {
            try
            {
                string group;
                Console.WriteLine("Введите id группы по которой будет заполняться файл");
                group = Console.ReadLine();
                Console.WriteLine("Введите день от которого будет заполнено расписание(в виде DD.MM.YYYY)");
                string start_day = Console.ReadLine();
                Console.WriteLine("Введите день к которому будет заполнено расписание(в виде DD.MM.YYYY)");
                string finish_day = Console.ReadLine();

                Console.WriteLine("Выбирите желаемое действие и нажмите Enter");
                Console.WriteLine("1 - Перезаписать файл");
                Console.WriteLine("2 - Дописать файл");
                Console.WriteLine("Любую другую кнопку чтобы не предпринимать никаких действий");
                string choice = Console.ReadLine();
                if (choice == "1")
                {
                    GET("https://schedule.sumdu.edu.ua/index/json", CreateParamGetResponseSumDU(start_day, finish_day, group), choice);
                }
                else if (choice == "2")
                {
                    GET("https://schedule.sumdu.edu.ua/index/json", CreateParamGetResponseSumDU(start_day, finish_day, group), choice);
                }
                else
                { }
            }
            catch (Exception)
            {
                Console.WriteLine("Произошла ошибка! Попробуйте ещё раз!");
            }
        }
    }
}