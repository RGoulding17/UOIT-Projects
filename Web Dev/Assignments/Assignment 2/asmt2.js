// Created By: Ryan Goulding(100556101) And Justin Estaris(100528069)

$(document).ready(function() {
    $('#weather').hide()
    $('#forecast').hide()
    $("#goButton").on("click", function(){DownloadWeather()});
});

function DownloadWeather(){
    $.ajax({
        type: "GET",
        url: "http://api.apixu.com/v1/forecast.json?q=43.944847,-78.891703&key=02d43d449a384c8e92d232342191403",
        dataType: "JSON",
        success: function(data) {
            ProcessWeather(data);
        },
        error: function(data) {
            console.log(data)
        } 
    });
}

function ProcessWeather(data){
    console.log(data)
    var html = "<div><h4>Temperature</h4><p>Current: "+data["current"]['temp_c']+"°C</br>Low: "+
                data["forecast"]['forecastday'][0]['day']['mintemp_c']+"°C</br>High: "+data["forecast"]['forecastday'][0]['day']['maxtemp_c']+
                "°C</br>Feels Like: "+data["current"]['feelslike_c']+"°C</p></div></br>"
    html += "<div><h4>Condition</h4><p>"+data["current"]['condition']["text"]+"</br>Cloud Cover: "+
            data["current"]['cloud']+"%</br>Humidity: "+data["current"]['humidity']+
            "%</br>Feels Like: "+data["current"]['pressure_mb']+"mB</p></div></br>"
    html += "<div><h4>Wind</h4><p>Direction: "+data["current"]['wind_dir']+"</br>Speed: "+
            data["current"]['wind_kph']+"km/h</p></div>"

    $("#weather").append(html)
    DownloadForecast()
}   

function DownloadForecast(){
    $.ajax({
        type: "GET",
        url: "http://api.apixu.com/v1/forecast.json?q=43.944847,-78.891703&days=7&key=02d43d449a384c8e92d232342191403",
        dataType: "JSON",
        success: function(data) {
            ProcessForecast(data);
        },
        error: function(data) {
            console.log(data)
        } 
    });
}

function ProcessForecast(data){
    var html = "<h2>Forecast</h2><table class='table'><thead><tr><th>Date</th><th>Condition</th><th>High</th><th>Low</th><th>Wind Speed</th><th>Outlook</th></thead><tbody>"

    for(i = 0; i<data['forecast']['forecastday'].length;i++){
        html += "<tr><td>"+data['forecast']['forecastday'][i]['date']+"</td>"+
                "<td><img src='http:"+data['forecast']['forecastday'][i]['day']['condition']['icon']+"'></td>"+
                "<td>"+data['forecast']['forecastday'][i]['day']['maxtemp_c']+"°C</td>"+
                "<td>"+data['forecast']['forecastday'][i]['day']['mintemp_c']+"°C</td>"+
                "<td>"+data['forecast']['forecastday'][i]['day']['maxwind_kph']+"km/h</td>"+
                "<td>"+data['forecast']['forecastday'][i]['day']['condition']['text']+"</td></tr>"
    }

    html +="</tbody></table>"
    $("#forecast").append(html)
    $('#weather').show()
    $('#forecast').show()
}