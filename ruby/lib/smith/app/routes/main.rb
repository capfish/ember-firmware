module Smith
  module App
    class Application < Sinatra::Base

      get '/' do
        erb :index
      end

      # Handle captive portal test for OSX
      get '/library/test/success.html' do
        redirect to '/wireless_networks'
      end

    end
  end
end