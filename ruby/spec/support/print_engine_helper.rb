module PrintEngineHelper

  def printer_status(vars)
    {
      Smith::PRINTER_STATUS_KEY.to_sym =>
      {
        Smith::STATE_PS_KEY.to_sym => vars[:state],
      }
    }
  end

end