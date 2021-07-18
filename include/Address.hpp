#pragma once

#include <string>


struct Address
{
	std::string street_{};
	std::string town_{};
	std::string country_{};

	Address() = default;

	Address(std::string street, std::string town,
		std::string country)
		: street_(std::move(street))
		, town_(std::move(town))
		, country_(std::move(country))
	{}

	std::string GetStreet() const { return street_; }
	std::string GetTown() const { return town_; }
	std::string GetCountry() const { return country_; }
};
