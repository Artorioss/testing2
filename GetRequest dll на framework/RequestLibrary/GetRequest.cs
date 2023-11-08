using System;
using System.Collections.Generic;
using System.Configuration;
using System.IO;
using System.Net;
using System.Net.Cache;
using System.Net.Configuration;

namespace RequestLibrary
{
    public class GetRequest
    {
        private HttpWebRequest _request;

        public void Run(ref CookieContainer cookies)
        {
            ServicePointManager.ServerCertificateValidationCallback += (sender, certificate, chain, sslPolicyErrors) => true;
            _request = (HttpWebRequest)WebRequest.Create(Address);

            _request.Headers.Add("DNT", "1");
            _request.Method = "Get";
            _request.Accept = Accept;
            _request.Host = Host;



            if (TurnOffProxy) _request.Proxy = null;
            else _request.Proxy = Proxy;

            if (UseUnsafeHeaderParsing)
            {
                var config = ConfigurationManager.OpenExeConfiguration(ConfigurationUserLevel.None);
                var settings = (SettingsSection)config.GetSection("system.net/settings");
                settings.HttpWebRequest.UseUnsafeHeaderParsing = true;
                config.Save(ConfigurationSaveMode.Modified);
                ConfigurationManager.RefreshSection("system.net/settings");
            }

            _request.AutomaticDecompression = DecompressionMethods.GZip | DecompressionMethods.Deflate;

            if (!(ContentType == string.Empty)) _request.ContentType = ContentType;

            if (TimeOut > 0)
            {
                _request.Timeout = TimeOut;
                _request.ReadWriteTimeout = TimeOut;
            }
            else
            {
                _request.Timeout = 35000;
                _request.ReadWriteTimeout = 35000;
            }

            if (NoCachePolicy == false)
            {
                var noCachePolicy = new HttpRequestCachePolicy(HttpRequestCacheLevel.NoCacheNoStore);
                _request.CachePolicy = noCachePolicy;
            }

            foreach (KeyValuePair<string, string> keyValuePair in Headers)
            {
                _request.Headers.Add(keyValuePair.Key, keyValuePair.Value);
            }
            if (UserAgent == null) _request.UserAgent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36";
            else _request.UserAgent = UserAgent;


            if (AllowAutoRedirect != null)
                _request.AllowAutoRedirect = (bool)AllowAutoRedirect;

            if (KeepAlive != null)
                _request.KeepAlive = (bool)KeepAlive;

            if (Expect100Continue != null)
                _request.ServicePoint.Expect100Continue = (bool)Expect100Continue;


            if (!(Referer == string.Empty))
                _request.Referer = Referer;

            _request.CookieContainer = cookies;

            try
            {
                HttpWebResponse response = (HttpWebResponse)_request.GetResponse();

                if ((response.StatusCode == HttpStatusCode.OK || response.StatusCode == HttpStatusCode.Moved || response.StatusCode == HttpStatusCode.Redirect) && response.ContentType.StartsWith("image", StringComparison.OrdinalIgnoreCase))
                {
                    writeFile("D:\\Разное\\Контент\\picture.jpg", response);
                }
                else if ((response.StatusCode == HttpStatusCode.OK || response.StatusCode == HttpStatusCode.Moved || response.StatusCode == HttpStatusCode.Redirect) && response.ContentType.StartsWith("video", StringComparison.OrdinalIgnoreCase))
                {
                    if (response.ResponseUri.ToString().Contains("trailers")) writeFile("D:\\Разное\\Контент\\video.gif", response);
                    else writeFile("D:\\Разное\\Контент\\video.mp4", response);
                }
                else
                {
                    var stream = response.GetResponseStream();
                    if (stream != null) Response = new StreamReader(stream).ReadToEnd();
                    ResponseHeaders = response.Headers;
                    RequestHeaders = _request.Headers;
                }


                response.Close();
            }
            catch (WebException ex)
            {
                using (var stream = ex.Response.GetResponseStream())
                using (var reader = new StreamReader(stream))
                {
                    Response = reader.ReadToEnd();
                }
            }
            catch (Exception ex)
            {
            }

        }

        private void writeFile(string filePath, HttpWebResponse response)
        {
            // if the remote file was found, download oit
            //string filePath = path; // Укажите путь и имя файла
            using (Stream inputStream = response.GetResponseStream())
            {
                using (FileStream fileStream = File.Create(filePath))
                {
                    byte[] buffer = new byte[64000];
                    int bytesRead;
                    while ((bytesRead = inputStream.Read(buffer, 0, buffer.Length)) > 0)
                    {
                        fileStream.Write(buffer, 0, bytesRead);
                    }
                }
            }
        }

        Dictionary<string, string> Headers = new Dictionary<string, string>();
        public void AddHeader(string headerName, string headerValue)
        {
            Headers[headerName] = headerValue;
        }
        public string filePath { get; set; }
        public bool NoCachePolicy { get; set; }
        public bool AcceptGZipEncoding { get; set; }
        public bool UseUnsafeHeaderParsing { get; set; }
        public string Address { get; set; }
        public string Accept { get; set; }
        public string Referer { get; set; }
        public string Host { get; set; }
        public bool? KeepAlive { get; set; }
        public string ContentType { get; set; }
        public bool? Expect100Continue { get; set; }
        public string Response { get; private set; }
        public bool? AllowAutoRedirect { get; set; }
        public WebHeaderCollection ResponseHeaders { get; private set; }
        public WebHeaderCollection RequestHeaders { get; private set; }
        public string UserAgent { get; set; }
        public WebProxy Proxy { get; set; }
        public bool TurnOffProxy { get; set; }
        public int TimeOut { get; set; }

    }
}

